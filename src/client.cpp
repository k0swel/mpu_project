#include "client.h"
#include "clients_func.h"
#include <QMessageBox>
#include <QCryptographicHash>
#include <notification.h>
#include "network_connection_state.h"
#include "json_manager.h"

extern QApplication a;

Client* Client::p_instance = nullptr;
Client* SingletonDestroyer::client_connection = nullptr;
QTcpSocket* SingletonDestroyer::socket = nullptr;
QTcpSocket* Client::socket = nullptr;

SingletonDestroyer Client::el = SingletonDestroyer();

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
   Client::socket = new QTcpSocket(this);
   connect(Client::socket, &QTcpSocket::connected, [&]() { connect(this->socket, &QTcpSocket::readyRead, this, &Client::read); }); // при подключении к серверу читаем сигналы поступления сообщений
   connect(Client::socket, &QTcpSocket::disconnected, this, &Client::disconnect_from_server); // при отключении от сервера вызываем функцию disconnect_from_server
   json_manager::create_json_file("./cache", "cache.json"); // создаём файл, где будет хранится инфа о кеше.
   this->ip = json_manager::get_data_from_json(json_manager::json_manager_network::Network).ip;
   this->port = json_manager::get_data_from_json(json_manager::json_manager_network::Network).port;
   this->connect_to_server();
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

QAbstractSocket::SocketState Client::get_socket_state() const
{
   return this->socket->state(); // возвращаем состояние сокета
}


void Client::connect_to_server() {
   this->socket->abort(); // отключаемся от подключений
   this->socket->connectToHost(this->ip, this->port); // подключаемся к серверу по IP и порту

}

void Client::read() {
   const QByteArray END_MARKER = ";end;";
    buffer.append(socket->readAll());

    int find_index;
    QString data_to_qstring;
    while ((find_index = buffer.indexOf(END_MARKER)) != -1) {
         // Извлекаем сообщение ДО маркера
         data_to_qstring = buffer.left(find_index);
         buffer = buffer.mid(find_index + END_MARKER.size());

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

         // СИГНАЛЫ ДЛЯ ОКНА СБРОСА ПАРОЛЯ
         if (data_to_qstring == "reset|error")
            emit this->reset_error(); // указанного логина не существует.

         if (data_to_qstring == "reset|succesfully_send_code_to_email") {
            emit this->signal_successfully_send_code_to_email(); // код успешно отправлен на email клиента
         }
         if (data_to_qstring == "reset|fail_send_code_to_email") {
            emit this->signal_fail_send_code_to_email();
         }

         // СИГНАЛЫ ГЛАВНОГО ОКНА КЛИЕНТА
         if (data_to_qstring.split("|")[0] == "answer") { // если текущий ответ от сервера содержит статус о решении уравнения
            QString answer = data_to_qstring.split("|")[1]; // вытаскиваем из ответа от сервера ответ
            if (answer != "error" and answer != "infinity_solutions" and answer != "no_solution")
               emit this->equation_ok(answer); // отправляем сигнал о решении уравнения.
            else
               emit this->equation_fail(answer); // отправляем сигнал об ошибке при решении уравнения.
         }
      }
   qDebug() << QString("%1 Server send: %2").arg(clients_func::get_client_time()).arg(data_to_qstring.simplified());
}

bool Client::write(QString text) {
   QByteArray data = text.toUtf8();
   if (this->socket->state() != QAbstractSocket::ConnectedState) {
      clients_func::create_messagebox("Ошибка", "Нет подключения к серверу, попробуйте перезапустить приложение", clients_func::dialog_style::NO_BTN);
      return false;
   }
   else {
      this->socket->write(data + ";end;");
      return true;
   }
}

void Client::disconnect_from_server() {
   this->socket->close();
   qDebug() << QString("%1 Произошло отключение от сервера!").arg(clients_func::get_client_time());
}
