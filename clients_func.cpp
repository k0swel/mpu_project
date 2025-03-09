#include "clients_func.h"
#include <QApplication>

bool clients_func::no_cyrillic(QString text) {
   if (text.size() > 1) {
      for (QChar ch: text) {
         if ((ch.toLatin1() >= 'A' and ch.toLatin1() <= 'Z') or (ch.toLatin1() >= 'a' and ch.toLatin1() <= 'z') or ch.isDigit() or ch.isPunct() or ch.isSymbol())  {
            continue;
         }
         else {
            return false;
         }
      }
      return true;
   }
   else {
      return false;
   }
}


bool clients_func::current_login(QString login) {

   if (clients_func::no_cyrillic(login) and login.size() >= 5) {
      return true;
   }
   return false;
}

bool clients_func::current_password(QString password) {
   bool is_upper = false;
   bool is_spec_symbol_and_no_cyrillic_and_number = clients_func::no_cyrillic(password);
   bool is_number = false;
   for (QChar symbol: password) {
      if (symbol.isUpper()) is_upper = true;
      if (symbol.isDigit()) is_number = true;
   }
   return (is_upper and is_spec_symbol_and_no_cyrillic_and_number);
}

bool clients_func::current_email(QString email) {
   QList parts_of_email = email.split(QChar('@'));
   if (parts_of_email.size() == 2 and email.size() <= 254) {
      QString local_part = parts_of_email.front();
      QString domain_part = parts_of_email.back();
      bool local_part_bool = clients_func::no_cyrillic(email);
      // РАССМАТРИВАЕМ ЛОКАЛЬНУЮ ЧАСТЬ
      bool domain_part_bool = true;
      if (!local_part.startsWith('.')) local_part_bool = local_part_bool & true; // если первый символ доменной части не является точкой.
      else local_part_bool = local_part_bool & false;

      // РАССМАТРИВАЕМ ДОМЕННУЮ ЧАСТЬ
      if (domain_part.count(QChar('.')) >= 2) domain_part_bool = domain_part_bool & true;
      return (local_part_bool & domain_part_bool);
   }
   else {
      return false;
   }
}
