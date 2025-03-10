#include "client.h"
#include "clients_func.h"



Client::Client()
{
   this->socket = new QTcpSocket();
   connect(this->socket, &QTcpSocket::connected, this, &Client::connect_to_server); // при подключении к серверу вызываем функцию connect_to_server
   connect(this->socket, &QTcpSocket::disconnected, this, &Client::disconnect_from_server); // при отключении от сервера вызываем функцию disconnect_from_server
   socket->connectToHost("127.0.0.1", port);
}

Client::~Client() {
   delete this->socket;
}

void Client::connect_to_server() {
   connect(this->socket, &QTcpSocket::readyRead, this, &Client::read); // при отправлении сообщения от сервера - читаем сообщение
}

void Client::read() {
   QByteArray data;
   while (this->socket->bytesAvailable() > 0) {
      data.append(this->socket->readAll());
   }
   qDebug() << QString("%1 Server send: %2").arg(clients_func::get_client_time()).arg(QString(data).simplified());
}

void Client::write(QString text) {
   QByteArray data = text.toUtf8();
   socket->write(data);
}

void Client::disconnect_from_server() {
   this->socket->close();
   qDebug() << QString("%1 Произошло отключение от сервера!").arg(clients_func::get_client_time());
   delete this;
}
