#include "client_object.h"
#include "functions_for_server.h"
#include <QList>
#include <QByteArray>
#include "dbsingleton.h"
#include <QThread>
extern QList<client*> clients;
extern functions_for_server* servers_functions;
//DBSingleton* DBSingleton = DBSingleton::getInstance();
client::client(QTcpSocket* client_socket, QObject* parent): QObject(parent), client_socket(client_socket)
{
   client_socket->setParent(this);
}

client::~client() {
   qInfo() << "Деструктор клиента вызван успешно!";
   clients.removeAll(this);
   this->client_socket->deleteLater();
   this->bye_message(); // вызываем прощальное сообщение
   emit this->del_thread(); // вызываем сигнал удаления потока
}

void client::initialization() {
   qInfo() << "ID потока клиента: " << QThread::currentThreadId();
   hello_message(); // отправляем в консоль приветственное сообщение. Статическая функция.
   connect(client_socket, &QTcpSocket::readyRead, this, &client::slot_read_from_client); // читаем сообщения от клиента
   connect(client_socket, &QTcpSocket::disconnected, this, &client::slot_close_connection); // если сокет отключается от сервера, вызываем функцию slot_close_connection

   // CONNECTЫ ДЛЯ ВЗАИМОДЕЙСТВИЯ С КЛИЕНТОМ

   // РЕГИСТРАЦИЯ
   connect(this, &client::signal_register_new_account, DBSingleton::getInstance(), &DBSingleton::slot_register_new_account); // процесс регистрации аккаунта
   //connect(DBSingleton::getInstance(), &DBSingleton::register_ok, this, &client::slot_register_ok); // успешная регистрация
   //connect(DBSingleton::getInstance(), &DBSingleton::register_error, this, &client::slot_register_error); // ошибка при регистрации

   //АВТОРИЗАЦИЯ
   connect(this, &client::signal_auth, DBSingleton::getInstance(), &DBSingleton::slot_auth); // процесс авторизации
   //connect(DBSingleton::getInstance(), &DBSingleton::auth_ok, this, &client::slot_auth_ok); // успешная авторизация
   //connect(DBSingleton::getInstance(), &DBSingleton::auth_error, this, &client::slot_auth_error); // ошибка при авторизации.


   // СБРОС ПАРОЛЯ
   connect(this, &client::signal_send_code_to_email, DBSingleton::getInstance(), &DBSingleton::slot_send_code); // CONNECT для отправки кода клиенту.
   //connect(DBSingleton::getInstance(), &DBSingleton::reset_error, this, &client::slot_reset_error); // CONNECT для отправки клиенту ошибки при сбросе пароля.
   connect(this, &client::signal_set_new_password, DBSingleton::getInstance(), &DBSingleton::slot_new_password); // CONNECT для установки нового пароля клиенту.

   // ГЛАВНОЕ КЛИЕНТСКОЕ ОКНО
   connect(this, &client::signal_linear_equation, servers_functions, &functions_for_server::slot_linear_equation); // CONNECT для решения линейного уравнения
   connect(this, &client::signal_quadratic_equation, servers_functions, &functions_for_server::slot_quadratic_equation); // CONNECT для решения квадратного уравнения.
   //connect(servers_functions, &functions_for_server::signal_equation_solution, this, &client::slot_equation_solution);  // CONNECT для отправки решения уравнения
}

void client::slot_read_from_client() {
   qInfo() << "Сработал " << Q_FUNC_INFO << " . Текущий поток - " << QThread::currentThreadId();
   QByteArray data_byte_array;
   QString data;
   data_byte_array.push_back(client_socket->readAll());  // помещаем сообщение от клиента в data.
   int end_symbol_in_message_pos;
   while ((end_symbol_in_message_pos = data_byte_array.indexOf(end_symbols)) != -1) {
      data = data_byte_array.left(end_symbol_in_message_pos);
      data_byte_array = data_byte_array.mid(end_symbol_in_message_pos + end_symbols.size());
      QString action = data.split("|")[0]; // вытаскиваем из сообщения клиента действие
      QString clients_data = data.split("|")[1]; // вытаскиваем данные из сообщения клиента

      // РЕГИСТРАЦИЯ
      if (action == "reg") {
         QStringList clients_data_list = clients_data.split("$"); // получаем список из данных пользователя
         QString login = clients_data_list[0]; // логин
         QString password = clients_data_list[1]; // пароль
         QString email = clients_data_list[2]; // почта
         QString last_name = clients_data_list[3]; // фамилия
         QString first_name = clients_data_list[4]; // имя
         QString middle_name = clients_data_list[5]; // отчество
         emit signal_register_new_account(login,password,email, last_name, first_name, middle_name, this); // посылаем сигнал на регистрацию аккаунта.
      }


      // АВТОРИЗАЦИЯ
      if (action == "login") {
         QString login = clients_data.split("$")[0]; // парсим логин
         QString password = clients_data.split("$")[1]; // парсим пароль.
         emit this->signal_auth(login, password, this); // отправляем сигнал авторизации в класс functions_for_server
      }

      // СБРОС ПАРОЛЯ
      if (action == "reset") { // ОТПРАВКА КОДА НА ПОЧТУ КЛИЕНТА
         QString email = clients_data.split("$")[0]; // вытаскиваем из данных клиента почту.
         QString code = clients_data.split("$")[1]; // вытаскиваем из данных клиента код, который нужно отправить на почту
         emit signal_send_code_to_email(email, code, this); // отправляем сигнал на отправку кода на почту
      }
      if (action == "new_password") {
         QString login = clients_data.split("$")[0]; // вытаскиваем из данных клиента логин.
         QString new_password = clients_data.split("$")[1]; // вытаскиваем из данных клиента новый пароль, который нужно установить на аккаунт
         emit signal_set_new_password(login, new_password, this); // отправляем сигнал на установку нового пароля
      }

      // ГЛАВНОЕ КЛИЕНТСКОЕ ОКНО
      if (action == "equation") {
         QString type_equation = data.split("|")[1]; // вытаскиваем из сообшения клиента тип уравнения
         if (type_equation == QString("linear")) {
            QStringList List_with_koef = data.split("|")[2].split("$");
            QString a = List_with_koef[0]; // вытаскиваем коэффициент a
            QString b = List_with_koef[1]; // вытаскиваем коэффициент b
            emit this->signal_linear_equation(a,b, this); // вызываем сигнал решения линейного уравнения
         }
         if (type_equation == "quadratic") {
            QStringList List_with_koef = data.split("|")[2].split("$");
            QString a = List_with_koef[0]; // вытаскиваем коэффициент a
            QString b = List_with_koef[1]; // вытаскиваем коэффициент b
            QString c = List_with_koef[2]; // вытаскиваем коэффициент c
            emit this->signal_quadratic_equation(a,b,c, this); // вызываем сигнал решения линейного уравнения
         }
      }

      qInfo() << QString("%1 Client ").arg(servers_functions->get_server_time()) << &client_socket << QString(" send message: %1").arg(QString(data)).simplified();
   }
}

void client::slot_close_connection() { // слот если клиент закрыл соединение с сервером.
   this->client_socket->close();
   this->deleteLater(); // удаляем экземпляр класса
}

void client::slot_register_ok() { // слот если клиент успешно зарегистрирован
   this->send_message("register|ok"); // отправляем клиенту сообщение об успешной регистрации
}

void client::slot_register_error() { // слот если произошла ошибка по время регистрации
   this->send_message("register|error"); // отправляем клиенту сообщение об ошибке при регистрации
}

void client::slot_auth_ok() // слот если авторизация прошла успешно
{
   this->send_message("auth|ok"); // отправляем клиенту сообщение об успешной авторизации.
}

void client::slot_auth_error() // слот если произошла ошибка при авторизации
{
   this->send_message("auth|error"); // отправляем клиенту сообщение об ошибке при авторизации.
}

void client::slot_reset_error()
{
   this->send_message("reset|error"); // отправляем клиенту сообщение о том, что указанный аккаунт не зарегистрированю
}

void client::slot_reset_ok()
{
    this->send_message("reset|ok"); // отправляем клиенту сообщение о том, что сброс пароля прошел успешно
}

void client::slot_fail_send_email_to_client() {
   this->send_message("reset|fail_send_code_to_email");
}

void client::slot_successfully_send_email_to_client() {
   this->send_message("reset|succesfully_send_code_to_email");
}

void client::slot_equation_solution(QString answer) // слот для отправки решения уравнения
{
   qInfo() << "Отправлено клиенту: " << answer;
   this->send_message(answer.toUtf8()); // отправляем клиенту сообщение о статусе решения уравнения)
}

// СЛУЖЕБНЫЕ ФУНКЦИИ ДЛЯ РАБОТЫ В РАМКАХ КЛАССА

void client::hello_message() { // функция отправки сообщения в консоль при каждом новом подключении

   if (clients.size() == 1) {
      qInfo() << QString("%1 Client socket has connected. Сurrently 1 socket is connected").arg(servers_functions->get_server_time());
    }
    else if (clients.size() > 1) {
       qInfo() << QString("%1 Client socket has connected. Сurrently %2 sockets are connected").arg(servers_functions->get_server_time()).arg(QString::number(clients.size()));
    }
}

void client::bye_message() { // функция отправки сообщения в консоль при каждом отключении
   if (clients.size() == 0)
      qInfo() << QString("%1 The client has disconnected. No clients at the moment").arg(servers_functions->get_server_time());
   else if (clients.size() == 1)
      qInfo() << QString("%1 The client has disconnected. Сurrently 1 socket is connected").arg(servers_functions->get_server_time());
   else if (clients.size() > 1)
      qInfo() << QString("%1 The client has disconnected. Сurrently %2 sockets are connected").arg(servers_functions->get_server_time()).arg(QString::number(clients.size()));
}

void client::send_message(QString message) // отправляем клиенту сообщение
{
   message = message + QString(";end;");
   qInfo() << "message = " << message;
   this->client_socket->write(message.toUtf8());
}
