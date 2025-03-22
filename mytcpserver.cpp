#include "mytcpserver.h"
#include <QDebug>
#include <QCoreApplication>
#include <QString>
#include "client_object.h"

QList<client*> clients;
functions_for_server* servers_functions = functions_for_server::get_instance(); // методы сервера;
MyTcpServer* MyTcpServer::p_instance = nullptr;
MyTcpServerDestroyer* MyTcpServer::destroyer = nullptr;


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
    mTcpServer = new QTcpServer(); // создаём сервер динамическим путём
    connect(mTcpServer, &QTcpServer::newConnection,
            this, &MyTcpServer::slotNewConnection);

    if(!mTcpServer->listen(QHostAddress::Any, 33333)){
        qDebug() << QString("%1 server is not started!").arg(servers_functions->get_server_time());
    } else {
        //server_status=1;
        qDebug() << QString("%1 server is started").arg(servers_functions->get_server_time());
    }
}

MyTcpServer* MyTcpServer::create_instance() {
   if (MyTcpServer::p_instance == nullptr) {
      MyTcpServer::p_instance = new MyTcpServer();
      MyTcpServer::destroyer = new MyTcpServerDestroyer();
      MyTcpServer::destroyer->initialize(MyTcpServer::p_instance, servers_functions);
   }
   return MyTcpServer::p_instance;
}

void MyTcpServer::slotNewConnection(){ // слот, который активируется при каждом подключении клиента к серверу.
        QTcpSocket* temp = this->mTcpServer->nextPendingConnection();
        client* client_object = new client(temp->socketDescriptor()); // создаём клиента и запускам его поток
        connect(client_object, &QThread::finished, client_object, &client::deleteLater); // когда у клиента не останется сообщений, он уничтожится.
}

