#include "clients_func.h"
#include <QApplication>

bool clients_func::english_symbols(QString text) {
   if (text.size() > 1) {
      for (QChar ch: text) {
         if (ch != QChar('$') and ch != QChar('|')) {
            if ((ch.toLatin1() >= 'A' and ch.toLatin1() <= 'Z') or (ch.toLatin1() >= 'a' and ch.toLatin1() <= 'z') or ch.isDigit() or ch.isPunct() or ch.isSymbol())
               continue;
            else {
               qDebug () << "НЕВЕРНЫЙ СИМВОЛ = " << ch;
               return false;
            }
         }
         else return false;
      }
      return true;
   }
   else {
      return false;
   }
}


bool clients_func::current_login(QString login) {
   bool english_symbols = false;

   // проверка на английские символы
   if (clients_func::english_symbols(login) and login.size() >= 5) {
      english_symbols = true;
   }
   return english_symbols;
}

bool clients_func::current_password(QString password) {
   bool is_upper = false;
   bool english_symbols = false;
   bool is_digits = false;
   bool is_spec_symbols = false;
   bool length_password_equal_or_more_5 = false;

   // проверка на английские символы
   if (clients_func::english_symbols(password)) {
      english_symbols = true;
   }

   // проверка на наличие спец символов, цифр и больших букв
   for (QChar symbol: password) {
      if (symbol.isUpper()) is_upper = true; // заглавные символы
      if (symbol.isDigit()) is_digits = true; // цифры
      if (symbol.isPunct() or symbol.isSymbol()) is_spec_symbols = true; // спец символы
    }

   if (password.length() >= 5) {
      length_password_equal_or_more_5 = true;
   }
   return is_upper & english_symbols & is_digits & is_spec_symbols & length_password_equal_or_more_5;
}

bool clients_func::current_email(QString email) {
   QList parts_of_email = email.split(QChar('@'));
   if (parts_of_email.size() == 2 and email.size() <= 254) {
      QString local_part = parts_of_email.front();
      QString domain_part = parts_of_email.back();
      bool local_part_bool = clients_func::english_symbols(local_part);
      bool domain_part_bool = clients_func::english_symbols(domain_part);
      // РАССМАТРИВАЕМ ЛОКАЛЬНУЮ ЧАСТЬ
      if (!local_part.startsWith('.')) local_part_bool = local_part_bool & true; // если первый символ доменной части не является точкой.
      else local_part_bool = local_part_bool & false;

      // РАССМАТРИВАЕМ ДОМЕННУЮ ЧАСТЬ
      if (domain_part.count(QChar('.')) >= 1) domain_part_bool = domain_part_bool & true;
      return (local_part_bool & domain_part_bool);
   }
   else {
      return false;
   }
}

QString clients_func::get_client_time() {
   time_t now_time = time(nullptr); // получаем время на сервере в данный момент.
   tm* time_struct = localtime(&now_time); // конвертируем время в удобную структуру (год, месяц, число, день, час, минута, секунда, миллисекунда)
   char time_format[100];
   strftime(time_format, sizeof(time_format), "[%b %d %Y %H:%M:%S]", time_struct);
   return QString(time_format);
}
