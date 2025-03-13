#include "client.h"
#include "clients_func.h"
#include <QMessageBox>

Client* Client::p_instance = nullptr;
Client* SingletonDestroyer::client_connection = nullptr;
QTcpSocket* SingletonDestroyer::socket = nullptr;
QTcpSocket* Client::socket = nullptr;

SingletonDestroyer Client::el = SingletonDestroyer();

int Client::port = 33333;

void SingletonDestroyer::initialize(Client* element,QTcpSocket* socket) {
   SingletonDestroyer::client_connection = element;
   SingletonDestroyer::socket = socket;
}

SingletonDestroyer::SingletonDestroyer() {}

SingletonDestroyer::~SingletonDestroyer() {
   qDebug() << "Вызвался деструктор SingletonDestroyer";
   delete SingletonDestroyer::socket;
   delete SingletonDestroyer::client_connection;
}

Client::Client()
{
   qDebug() << "Вызвался конструктор клиента";
   Client::socket = new QTcpSocket();
   connect(Client::socket, &QTcpSocket::connected, this, &Client::connect_to_server); // при подключении к серверу вызываем функцию connect_to_server
   connect(Client::socket, &QTcpSocket::disconnected, this, &Client::disconnect_from_server); // при отключении от сервера вызываем функцию disconnect_from_server
   Client::socket->connectToHost("127.0.0.1", 33333);
}

Client::~Client() {}

Client* Client::get_instance() {
   if (Client::p_instance == nullptr) {
      Client::p_instance = new Client();
      SingletonDestroyer::initialize(Client::p_instance, Client::socket);

   }
   return Client::p_instance;
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
   if (this->socket->state() != QAbstractSocket::ConnectedState) {
      QMessageBox::information(nullptr, "Ошибка", "Нет подключения к серверу, попробуйте перезапустить приложение");
   }
   else
      this->socket->write(data);
}

void Client::disconnect_from_server() {
   this->socket->close();
   qDebug() << QString("%1 Произошло отключение от сервера!").arg(clients_func::get_client_time());
}
