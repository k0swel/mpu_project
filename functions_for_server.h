#ifndef FUNCTIONS_FOR_SERVER_H
#define FUNCTIONS_FOR_SERVER_H
#include <QString>
#include <ctime>
#include <QObject>

class functions_for_server: public QObject
{
   Q_OBJECT
private:
   functions_for_server();
   functions_for_server(const functions_for_server&);
   static functions_for_server* p_instance;

public:
   static functions_for_server* get_instance();
   QString get_server_time();

signals:
   // РЕГИСТРАЦИЯ
   void register_ok(); // сигнал об успешной регистрации
   void register_error(); // сигнал об ошибке при регистрации.

   // АВТОРИЗАЦИЯ
   void auth_ok(); // сигнал об успешной авторизации.
   void auth_error(); // сигнал об ошибке при авторизации.

public slots:
   // РЕГИСТРАЦИЯ
   void slot_register_new_account(QString login, QString password, QString email, QString date_of_birthday, QString last_name, QString first_name, QString middle_name); // слот для регистрации аккаунта

   // АВТОРИЗАЦИЯ
   void slot_auth(QString login, QString password);
   // СБРОС ПАРОЛЯ
   void slot_send_code(QString email, QString code); // функция отправки кода на почту клиента.
   void slot_new_password(QString email, QString password); // функция для установки нового пароля клиенту.
};

#endif // FUNCTIONS_FOR_SERVER_H
