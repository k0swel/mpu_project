#include "client_object.h"
#include <functions_for_server.h>
#include <QList>
#include "client_object.h"
#include <QByteArray>

extern QList<client*> clients;
extern functions_for_server* servers_functions;

client::client(qintptr client_description, QObject* parent): QObject(parent), client_description(client_description)
{
   initialization();
}

client::~client() {
   qDebug() << "Деструктор клиента вызван успешно!";
   clients.removeAll(this);
   this->client_socket->close();
   this->bye_message(); // вызываем прощальное сообщение
   emit this->del_thread(); // вызываем сигнал удаления потока
}

void client::initialization() {
   client_socket = new QTcpSocket(this); // вот сокет.
   client_socket->setSocketDescriptor(client_description); // мы создали новый сокет и идентифицируем его дескриптором уже существующим
   clients.push_back(this); // добавляем клиента в конец списка
   hello_message(); // отправляем в консоль приветственное сообщение. Статическая функция.
   connect(client_socket, &QTcpSocket::readyRead, this, &client::slot_read_from_client); // читаем сообщения от клиента
   connect(client_socket, &QTcpSocket::disconnected, this, &client::slot_close_connection); // если сокет отключается от сервера, вызываем функцию slot_close_connection

   // CONNECTЫ ДЛЯ ВЗАИМОДЕЙСТВИЯ С КЛИЕНТОМ

   // РЕГИСТРАЦИЯ
   connect(this, &client::signal_register_new_account, servers_functions, &functions_for_server::slot_register_new_account); // процесс регистрации аккаунта
   connect(servers_functions, &functions_for_server::register_ok, this, &client::slot_register_ok); // успешная регистрация
   connect(servers_functions, &functions_for_server::register_error, this, &client::slot_register_error); // ошибка при регистрации

   //АВТОРИЗАЦИЯ
   connect(this, &client::signal_auth, servers_functions, &functions_for_server::slot_auth); // процесс авторизации
   connect(servers_functions, &functions_for_server::auth_ok, this, &client::slot_auth_ok); // успешная авторизация
   connect(servers_functions, &functions_for_server::auth_error, this, &client::slot_auth_error); // ошибка при авторизации.


   // СБРОС ПАРОЛЯ
   connect(this, &client::signal_send_code_to_email, servers_functions, &functions_for_server::slot_send_code); // CONNECT для отправки кода клиенту.
   connect(this, &client::signal_set_new_password, servers_functions, &functions_for_server::slot_new_password); // CONNECT для установки нового пароля клиенту.

   // ГЛАВНОЕ КЛИЕНТСКОЕ ОКНО
   connect(this, &client::signal_linear_equation, servers_functions, &functions_for_server::slot_linear_equation); // CONNECT для решения линейного уравнения
   connect(this, &client::signal_quadratic_equation, servers_functions, &functions_for_server::slot_quadratic_equation); // CONNECT для решения квадратного уравнения.
   connect(servers_functions, &functions_for_server::signal_equation_solution, this, &client::slot_equation_solution);  // CONNECT для отправки решения уравнения
}

void client::slot_read_from_client() {
   qDebug() << "Сработал " << Q_FUNC_INFO << " . Текущий поток - " << QThread::currentThreadId();
   QString data;
   while (client_socket->bytesAvailable()) { // читаем сообщение от клиента
      data.push_back(client_socket->readAll());  // помещаем сообщение от клиента в data.
   }
   QString action = data.split("|")[0]; // вытаскиваем из сообщения клиента действие
   QString clients_data = data.split("|")[1]; // вытаскиваем данные из сообщения клиента

   // РЕГИСТРАЦИЯ
   if (action == "reg") {
      QStringList clients_data_list = clients_data.split("$"); // получаем список из данных пользователя
      QString login = clients_data_list[0]; // логин
      QString password = clients_data_list[1]; // пароль
      QString email = clients_data_list[2]; // почта
      QString date_of_birthday = clients_data_list[3]; // дата рождения
      QString last_name = clients_data_list[4]; // фамилия
      QString first_name = clients_data_list[5]; // имя
      QString middle_name = clients_data_list[6]; // отчество
      emit signal_register_new_account(login,password,email, date_of_birthday, last_name, first_name, middle_name); // посылаем сигнал на регистрацию аккаунта.
   }


   // АВТОРИЗАЦИЯ
   if (action == "login") {
      QString login = clients_data.split("$")[0]; // парсим логин
      QString password = clients_data.split("$")[1]; // парсим пароль.
      emit this->signal_auth(login, password); // отправляем сигнал авторизации в класс functions_for_server
   }

   // СБРОС ПАРОЛЯ
   if (action == "reset") { // ОТПРАВКА КОДА НА ПОЧТУ КЛИЕНТА
      QString email = clients_data.split("$")[0]; // вытаскиваем из данных клиента почту.
      QString code = clients_data.split("$")[1]; // вытаскиваем из данных клиента код, который нужно отправить на почту
      emit signal_send_code_to_email(email, code); // отправляем сигнал на отправку кода на почту
   }
   if (action == "new_password") {
      QString email = clients_data.split("$")[0]; // вытаскиваем из данных клиента почту.
      QString new_password = clients_data.split("$")[1]; // вытаскиваем из данных клиента новый пароль, который нужно установить на аккаунт
      emit signal_set_new_password(email, new_password); // отправляем сигнал на установку нового пароля
   }

   // ГЛАВНОЕ КЛИЕНТСКОЕ ОКНО
   if (action == "equation") {
      QString type_equation = data.split("|")[1]; // вытаскиваем из сообшения клиента тип уравнения
      if (type_equation == QString("linear")) {
         QStringList List_with_koef = data.split("|")[2].split("$");
         QString a = List_with_koef[0]; // вытаскиваем коэффициент a
         QString b = List_with_koef[1]; // вытаскиваем коэффициент b
         emit this->signal_linear_equation(a,b); // вызываем сигнал решения линейного уравнения
      }
      if (type_equation == "quadratic") {
         qDebug() << "Test2";
         QStringList List_with_koef = data.split("|")[2].split("$");
         QString a = List_with_koef[0]; // вытаскиваем коэффициент a
         QString b = List_with_koef[1]; // вытаскиваем коэффициент b
         QString c = List_with_koef[2]; // вытаскиваем коэффициент c
         emit this->signal_quadratic_equation(a,b,c); // вызываем сигнал решения линейного уравнения
      }
   }

   qDebug() << QString("%1 Client ").arg(servers_functions->get_server_time()) << &client_socket << QString(" send message: %1").arg(QString(data)).simplified();
   //this->client_socket.write(data.toUtf8()); // ОТПРАВЛЯЕМ ОТПРАВЛЕННОЕ СООБЩЕНИЕ ОБРАТНО КЛИЕНТУ
}

void client::slot_close_connection() { // слот если клиент закрыл соединение с сервером.
   this->client_socket->close();
   this->deleteLater(); // удаляем экземпляр класса
}

void client::slot_register_ok() { // слот если клиент успешно зарегистрирован
   this->client_socket->write("register|ok"); // отправляем клиенту сообщение об успешной регистрации
}

void client::slot_register_error() { // слот если произошла ошибка по время регистрации
   this->client_socket->write("register|error"); // отправляем клиенту сообщение об ошибке при регистрации
}

void client::slot_auth_ok() // слот если авторизация прошла успешно
{
   this->client_socket->write("auth|ok"); // отправляем клиенту сообщение об успешной авторизации.
}

void client::slot_auth_error() // слот если произошла ошибка при авторизации
{
   this->client_socket->write("auth|error"); // отправляем клиенту сообщение об ошибке при авторизации.
}

void client::slot_equation_solution(QString answer) // слот для отправки решения уравнения
{
   this->client_socket->write(answer.toUtf8()); // отправляем клиенту сообщение о статусе решения уравнения)
}

// СЛУЖЕБНЫЕ ФУНКЦИИ ДЛЯ РАБОТЫ В РАМКАХ КЛАССА

void client::hello_message() { // функция отправки сообщения в консоль при каждом новом подключении

   if (clients.size() == 1) {
      qDebug() << QString("%1 Client socket has connected. Сurrently 1 socket is connected").arg(servers_functions->get_server_time());
    }
    else if (clients.size() > 1) {
       qDebug() << QString("%1 Client socket has connected. Сurrently %2 sockets are connected").arg(servers_functions->get_server_time()).arg(QString::number(clients.size()));
    }
}

void client::bye_message() { // функция отправки сообщения в консоль при каждом отключении
   if (clients.size() == 0)
      qDebug() << QString("%1 The client has disconnected. No clients at the moment").arg(servers_functions->get_server_time());
   else if (clients.size() == 1)
      qDebug() << QString("%1 The client has disconnected. Сurrently 1 socket is connected").arg(servers_functions->get_server_time());
   else if (clients.size() > 1)
      qDebug() << QString("%1 The client has disconnected. Сurrently %2 sockets are connected").arg(servers_functions->get_server_time()).arg(QString::number(clients.size()));
}
