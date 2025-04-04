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

   // ОКНО СБРОСА ПАРОЛЯ
   void reset_error(); // сигнал о том, что логин пользователя в БД не найден и соответственно некуда отправить код подтверждения.
   // ГЛАВНОЕ КЛИЕНТСКОЕ ОКНО
   void signal_equation_solution(QString); // сигнал о решении уравнения

public slots:
   // РЕГИСТРАЦИЯ
   void slot_register_new_account(QString login, QString password, QString email, QString last_name, QString first_name, QString middle_name); // слот для регистрации аккаунта

   // АВТОРИЗАЦИЯ
   void slot_auth(QString login, QString password);

   // СБРОС ПАРОЛЯ
   void slot_send_code(QString login, QString code); // функция отправки кода на почту клиента.
   void slot_new_password(QString login, QString password); // функция для установки нового пароля клиенту.

   // КЛИЕНТСКОЕ ОКНО
   void slot_linear_equation(QString a, QString b); // функция решения линейного уравнения
   void slot_quadratic_equation(QString a, QString b, QString c); // функция решения квадратного уравнения.
};

#endif // FUNCTIONS_FOR_SERVER_H
