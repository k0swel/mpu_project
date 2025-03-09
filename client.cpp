#include "client.h"



Client::Client()
{
   this->socket = new QTcpSocket();
   connect(this->socket, &QTcpSocket::connected, this, &Client::connect_to_server); // при подключении к серверу вызываем функцию connect_to_server
   socket->connectToHost("127.0.0.1", port);
}

QString Client::get_client_time() {
   time_t now_time = time(nullptr); // получаем время на сервере в данный момент.
   tm* time_struct = localtime(&now_time); // конвертируем время в удобную структуру (год, месяц, число, день, час, минута, секунда, миллисекунда)
   char time_format[100];
   strftime(time_format, sizeof(time_format), "[%b %d %Y %H:%M:%S]", time_struct);
   return QString(time_format);
}

void Client::connect_to_server() {
   connect(this->socket, &QTcpSocket::readyRead, this, &Client::read); // при отправлении сообщения от сервера - читаем сообщение
}

void Client::read() {
   QByteArray data;
   while (this->socket->bytesAvailable() > 0) {
      data.append(this->socket->readAll());
   }
   qDebug() << QString("%1 Server send: %2").arg(Client::get_client_time()).arg(QString(data).simplified());
}
