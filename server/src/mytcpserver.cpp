#include "mytcpserver.h"
#include <QDebug>
#include <QCoreApplication>
#include <QString>
#include <QThread>
#include "client_object.h"
#include "dbsingleton.h"

// ПЕРЕМЕННЫЕ ОКРУЖЕНИЯ
#include <QProcessEnvironment>
// --

MyTcpServer* MyTcpServer::p_instance = nullptr;
MyTcpServerDestroyer MyTcpServerDestroyer::destroyer = MyTcpServerDestroyer();

QList<client*> clients;
functions_for_server* servers_functions = functions_for_server::get_instance(); // методы сервера;

void MyTcpServerDestroyer::initialize(MyTcpServer* server, functions_for_server* functions) {
    this->server = server;
    this->functions = functions;
}

MyTcpServerDestroyer::~MyTcpServerDestroyer() {
   delete this->server;
   delete this->functions;
}

MyTcpServer::~MyTcpServer()
{
    for (int i = 0; i < clients.size(); i++) {
        delete clients[i];
    }
    mTcpServer->close(); // закрываем сервер.
    delete mTcpServer;
    //server_status=0;
}

MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent){ // включение сервера
    mTcpServer = new QTcpServer; // создаём сервер динамическим путём

    //db = DBSingleton::getInstance(); // Инициализация базы данных

    connect(mTcpServer, &QTcpServer::newConnection,
            this, &MyTcpServer::slotNewConnection); // связь для нового клиента

    if(!mTcpServer->listen(QHostAddress::Any, this->get_port("TMP_PORT"))){ // ищем порт в переменных окружения и прослушиваем его.
        qCritical() << QString("%1 server is not started!").arg(servers_functions->get_server_time());
        exit(3);

    } else {
        //server_status=1;
         qInfo() << "Server is start. It listen the port is: " << this->get_port("TMP_PORT");
         DBSingleton* db = DBSingleton::getInstance(); // База данных
    }
}

MyTcpServer* MyTcpServer::create_instance() {
   if (MyTcpServer::p_instance == nullptr) {
      MyTcpServer::p_instance = new MyTcpServer;
      MyTcpServerDestroyer::destroyer.initialize(MyTcpServer::p_instance, functions_for_server::get_instance());
   }
   return MyTcpServer::p_instance;
}

void MyTcpServer::slotNewConnection(){ // слот, который активируется при каждом подключении клиента к серверу.
       QTcpSocket* socket = mTcpServer->nextPendingConnection();

       QThread* thread = new QThread(this);
       client* clientObj = new client(socket->socketDescriptor());

       clientObj->moveToThread(thread);
       connect(clientObj, &client::del_thread, thread, &QThread::quit);
       connect(thread, &QThread::finished, thread, &QThread::deleteLater); // Удаляем сам поток
      connect(thread, &QThread::started, clientObj, &client::initialization);
       socket->setParent(nullptr); // Отвязываем сокет от сервера

       thread->start();
}


int MyTcpServer::get_port(QString environment_variable) {
   QProcessEnvironment env_process = QProcessEnvironment::systemEnvironment();
   if (env_process.contains(environment_variable)) {
      int port = env_process.value(environment_variable).toInt(); // возвращаем порт
      return port;
   }
   else {
      qDebug() << "Такой переменной окружения не существует";
      exit(2);
   }

}
