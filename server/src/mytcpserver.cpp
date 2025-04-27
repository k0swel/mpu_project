#include "../include/mytcpserver.h"
#include <QDebug>
#include <QCoreApplication>
#include <QString>
#include <QThread>
#include "../include/client_object.h"

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

    if(!mTcpServer->listen(QHostAddress::Any, 8080)){ // прослушиваем порт 8080
        qDebug() << QString("%1 server is not started!").arg(servers_functions->get_server_time());
    } else {
        //server_status=1;
        qDebug() << QString("%1 server is started").arg(servers_functions->get_server_time());
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
      QThread* new_thread_for_client = new QThread(this); // создаём новый поток для клиента
      QTcpSocket* temp = this->mTcpServer->nextPendingConnection();
      client* client_object = new client(temp->socketDescriptor()); // создаём клиента и запускам его поток
      client_object->moveToThread(new_thread_for_client); // помещаем объекта в новый поток
        connect(client_object, &client::del_thread, new_thread_for_client, &QThread::quit); // когда клиент завершает работу потока, мы его останавливаем
        connect(new_thread_for_client, &QThread::finished, client_object, &QThread::deleteLater); // когда поток объявляет о завершении работы, мы уничтожаем поток
      new_thread_for_client->start(); // запускаем поток.
}
