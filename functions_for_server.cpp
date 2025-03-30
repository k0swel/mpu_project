#include "functions_for_server.h"
#include <QDebug>

functions_for_server* functions_for_server::p_instance = nullptr;

functions_for_server::functions_for_server() {}

functions_for_server* functions_for_server::get_instance() {
   if (p_instance == nullptr) {
      p_instance = new functions_for_server();
   }
   return p_instance;
}


QString functions_for_server::get_server_time() {
   time_t now_time = time(nullptr); // получаем время на сервере в данный момент.
   tm* time_struct = localtime(&now_time); // конвертируем время в удобную структуру (год, месяц, число, день, час, минута, секунда, миллисекунда)
   char time_format[100];
   strftime(time_format, sizeof(time_format), "[%b %d %Y %H:%M:%S]", time_struct);
   return QString(time_format);
}

// РЕГИСТРАЦИЯ
void functions_for_server::slot_register_new_account(QString login, QString password, QString email, QString date_of_birthday, QString last_name, QString first_name, QString middle_name)
{
   qDebug() << QString("%1 Вызов функции functions_for_server::slot_register_new_account с аргументами login = %2 ; password = %3 ; email = %4 ; date_of_birthday = %5 ; last_name = %6 ; first_name = %7 ; middle_name = %8").arg(this->get_server_time()).arg(login).arg(password).arg(email).arg(date_of_birthday).arg(last_name).arg(first_name).arg(middle_name);
   if (true) // если успешная регистрация
      emit this->register_ok(); // сигнал об успешной регистрации.
   if (false) // если ошибка при регистрации
      emit this->register_error(); // сигнал об ошибке при регистрации.
}

// АВТОРИЗАЦИЯ
void functions_for_server::slot_auth(QString login, QString password) {
   qDebug() << QString("%1 Вызов функции functions_for_server::slot_auth с аргументами login = %2 ; password = %3").arg(this->get_server_time()).arg(login).arg(password);
   if (true) // если успешная авторизация
      emit this->auth_ok(); // отправляем сигнал об успешной авторизации.
   if (false) // если ошибка при авторизации
      emit this->auth_error(); // отправляем сигнал об ошибке при авторизации.
}



// СБРОС ПАРОЛЯ
void functions_for_server::slot_send_code(QString email, QString code)
{
   qDebug() << QString("%1 Вызов функции functions_for_server::slot_send_code с аргументами email = %2 ; code = %3").arg(this->get_server_time()).arg(email).arg(code);
   // РЕАЛИЗАЦИЯ ФУНКЦИИ ОТПРАВКИ КОДА НА ПОЧТУ.
}

void functions_for_server::slot_new_password(QString email, QString password)
{   qDebug() << QString("%1 Вызов функции functions_for_server::slot_new_password с аргументами email = %2 ; password = %3").arg(this->get_server_time()).arg(email).arg(password);


}
