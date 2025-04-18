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
void functions_for_server::slot_register_new_account(QString login, QString password, QString email, QString last_name, QString first_name, QString middle_name)
{
   qDebug() << QString("%1 Вызов функции functions_for_server::slot_register_new_account с аргументами login = %2 ; password = %3 ; email = %4 ; last_name = %5 ; first_name = %6 ; middle_name = %7").arg(this->get_server_time()).arg(login).arg(password).arg(email).arg(last_name).arg(first_name).arg(middle_name);
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
void functions_for_server::slot_send_code(QString login, QString code)
{
   qDebug() << QString("%1 Вызов функции functions_for_server::slot_send_code с аргументами login = %2 ; code = %3").arg(this->get_server_time()).arg(login).arg(code);

   if (true) { // ЗДЕСЬ ПРОВЕРКА НА ТО, ЧТО УКАЗАННЫЙ ЛОГИН СУЩЕСТВУЕТ
      // РЕАЛИЗАЦИЯ ФУНКЦИИ ОТПРАВКИ КОДА НА ПОЧТУ.
   }
   else if (false) {// ЕСЛИ УКАЗАННОГО ЛОГИНА НЕ СУЩЕСТВУЕТ, ТО ПОЛЬЗОВАТЕЛЬ СООТВЕТСТВЕННО НЕ ЗАРЕГИСТРИРОВАН.
      emit this->reset_error(); // вызываем сигнал об ошибке (не найден логин пользователя в БД)
   }
}

void functions_for_server::slot_new_password(QString login, QString password)
{   qDebug() << QString("%1 Вызов функции functions_for_server::slot_new_password с аргументами login = %2 ; password = %3").arg(this->get_server_time()).arg(login).arg(password);


}

void functions_for_server::slot_linear_equation(QString a, QString b)
{
   // ЛОГИКА РЕШЕНИЯ ЛИНЕЙНОГО УРАВНЕНИЯ
   int answer = 777; // тестовое решение уравнения
   QString solution;
   if (answer)  // если решение линейного уравнения существует
      solution = QString("answer|%1").arg(answer); // добавляем в строку, которую будем отправлять клиенту, решение линейного уравнения

   else // если решение линейного уравнения не существует
      solution = QString("answer|error"); // добавляем в строку информацию об ошибке при решении линейного уравнения

   emit this->signal_equation_solution(solution); // отправляем сигнал о решении линейного уравнения
}

void functions_for_server::slot_quadratic_equation(QString a, QString b, QString c)
{
   // ЛОГИКА РЕШЕНИЯ КВАДРАТНОГО УРАВНЕНИЯ УРАВНЕНИЯ
   QList<double>answers = {-1.5, 3}; // пример ответа
   QString solution; // переменная хранит решение уравнения
   if (!answers.isEmpty()) { // если массив ответов не пустой
      solution = QString("answer|");
      for (auto el: answers) {
         solution += QString("%1$").arg(el); // добавляем в строку каждый корень квадратного уравнения
      }
      solution.chop(1); // chop удаляет N символов с конца строки
   }
   else {
      solution = QString("answer|error"); // добавляем в строку информацию об ошибке при решении линейного уравнения
   }
   emit this->signal_equation_solution(solution); // отправляем сигнал о решении уравнения
}
