#include "client.h"
#include "clients_func.h"
#include <QMessageBox>

extern QApplication a;

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

Client::~Client() {
   qDebug() << "Вызвался деструктор клиента";
}

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

   QString data_to_qstring = QString(data);

   // СИГНАЛЫ ДЛЯ РЕГИСТРАЦИИ
   if (data_to_qstring == "register|ok")
      emit this->register_ok(); // успешная регистарция
   if (data_to_qstring == "register|error")
      emit this->register_error(); // ошибка при регистрации

   // СИГНАЛЫ ДЛЯ АВТОРИЗАЦИИ
   if (data_to_qstring == "auth|ok")
      emit this->auth_ok(); // успешная авторизация
   if (data_to_qstring == "auth|error")
      emit this->auth_error(); // ошибка при авторизации!

   // СИГНАЛЫ ГЛАВНОГО ОКНА КЛИЕНТА
   if (data_to_qstring.split("|")[0] == "answer") { // если текущий ответ от сервера содержит статус о решении уравнения
      QString answer = data_to_qstring.split("|")[1]; // вытаскиваем из ответа от сервера ответ
      if (answer != "error")
         emit this->equation_ok(QString(answer)); // отправляем сигнал о решении уравнения.
      else
         emit this->equation_fail(); // отправляем сигнал об ошибке при решении уравнения.
   }
   qDebug() << QString("%1 Server send: %2").arg(clients_func::get_client_time()).arg(data_to_qstring.simplified());
}

bool Client::write(QString text) {
   QByteArray data = text.toUtf8();
   if (this->socket->state() != QAbstractSocket::ConnectedState) {
      QMessageBox::information(nullptr, "Ошибка", "Нет подключения к серверу, попробуйте перезапустить приложение");
      return false;
   }
   else {
      this->socket->write(data);
      return true;
   }
}

void Client::disconnect_from_server() {
   this->socket->close();
   qDebug() << QString("%1 Произошло отключение от сервера!").arg(clients_func::get_client_time());
}
