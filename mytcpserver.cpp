#include "mytcpserver.h"
#include <QDebug>
#include <QCoreApplication>
#include <QString>



MyTcpServer::~MyTcpServer()
{
   while(sockets.size() > 0) { // закрываем сначала все клиентские сокеты
      sockets.back()->close();
      sockets.pop_back();
   }
   mTcpServer->close(); // закрываем сервер.
    //server_status=0;
}

MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent){ // включение сервера СДЕЛАНО
    mTcpServer = new QTcpServer(this); // создаём сервер динамическим путём
    servers_functions = functions_for_server::get_instance(); // методы сервера

    connect(mTcpServer, &QTcpServer::newConnection,
            this, &MyTcpServer::slotNewConnection);

    if(!mTcpServer->listen(QHostAddress::Any, 33333)){
        qDebug() << QString("%1 server is not started!").arg(servers_functions->get_server_time());
    } else {
        //server_status=1;
        qDebug() << QString("%1 server is started").arg(servers_functions->get_server_time());
    }
}

void MyTcpServer::slotNewConnection(){ // слот, который активируется при каждом подключении клиента к серверу.
 //   if(server_status==1){
        QTcpSocket* temp = mTcpServer->nextPendingConnection();
        sockets.push_back(temp);
        temp->write(QString("Welcome, user №%1").arg(sockets.size()).toUtf8()); // отправляем приветственное сообщение клиенту.
        if (sockets.size() == 1) {
           qDebug() << QString("%1 Client socket has connected. Сurrently 1 socket is connected").arg(servers_functions->get_server_time());
         }
         else if (sockets.size() > 1) {
            qDebug() << QString("%1 Client socket has connected. Сurrently %2 sockets are connected").arg(servers_functions->get_server_time()).arg(sockets.size());
         }
        connect(temp, &QTcpSocket::readyRead,this,&MyTcpServer::slotServerRead);
        connect(temp,&QTcpSocket::disconnected,this,&MyTcpServer::slotClientDisconnected);
   // }
}

void MyTcpServer::slotServerRead(){
   QTcpSocket* current_socket = qobject_cast<QTcpSocket*>(sender()); // сокет, который отправил сигнал
   QString data;
   while (current_socket->bytesAvailable() > 0) { // получаем ответ от клиента.
      data.push_back(current_socket->readAll());
   }
   qDebug() << QString("%1 Client ").arg(servers_functions->get_server_time()) << current_socket << QString(" send message: %1").arg(data).simplified();

}

void MyTcpServer::slotClientDisconnected(){ // слот активируется при отключении клиента от сервера СДЕЛАНО
   QTcpSocket* current_socket = qobject_cast<QTcpSocket*>(sender()); // сокет, который отправил сигнал
   current_socket->close();
   sockets.removeOne(current_socket);

   if (sockets.size() == 0)
      qDebug() << QString("%1 The client has disconnected. No clients at the moment").arg(servers_functions->get_server_time());
   else if (sockets.size() == 1)
      qDebug() << QString("%1 The client has disconnected. Сurrently 1 socket is connected").arg(servers_functions->get_server_time());
   else if (sockets.size() > 1)
      qDebug() << QString("%1 The client has disconnected. Сurrently %1 sockets are connected").arg(servers_functions->get_server_time()).arg(sockets.size());


}
