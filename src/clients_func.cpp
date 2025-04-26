#include "clients_func.h"
#include <QApplication>
#include <QVector>
#include <QRandomGenerator>
#include <QWidget>
#include <QLineEdit>
#include <QCryptographicHash>

bool clients_func::english_symbols(QString text) {
   if (text.size() > 1) {
      for (QChar ch: text) {
         if (ch != QChar('$') and ch != QChar('|')) {
            if ((ch.toLatin1() >= 'A' and ch.toLatin1() <= 'Z') or (ch.toLatin1() >= 'a' and ch.toLatin1() <= 'z') or ch.isDigit() or ch.isPunct() or ch.isSymbol())
               continue;
            else {
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

void clients_func::create_messagebox(QString title, QString message)
{
   QMessageBox msg_box;
   msg_box.setIcon(QMessageBox::Information); // устанавливаем иконку message box
   msg_box.setStyleSheet("QMessageBox { background-color: rgb(33, 35, 40) }; }"
                         "QMessageBox QLabel { color: white; }"); // устанавливаем визуальные стили message box
   msg_box.setWindowTitle(title); // устанавливаем заголовок message box
   msg_box.setText(message); // устанавливаем текст message box
   msg_box.exec(); // запускаем message box
}


bool clients_func::current_login(QString login) {
   bool english_symbols = false;
   bool is_spec_symbols = false;
   for (auto symbol: login) {
      if ( ((symbol.toLatin1() >= 'A' and symbol.toLatin1() <= 'Z') or (symbol.toLatin1() >= 'a' and symbol.toLatin1() <= 'z') or symbol.isDigit()) and symbol != QChar('|') and symbol != QChar('$'))
         english_symbols = true;
      else
         english_symbols = false;
   }
   return english_symbols;
}

bool clients_func::current_password(QString password) {
   bool english_symbols = false;
   bool is_spec_symbols = false;
   bool is_numbers = false;
   bool is_upper_symbols = false;
   bool length_password_equal_or_more_5 = false;

   // проверка на английские символы
   english_symbols = clients_func::english_symbols(password);

   // проверка на наличие спец.символа и цифр
   for(auto symbol: password) {
      if (symbol.isPunct())
         is_spec_symbols = true;

      if (symbol.isDigit())
         is_numbers = true;

      if (symbol.isUpper())
         is_upper_symbols = true;
   }

   // проверка на длину пароля больше 5
   if (password.length() >= 5) {
      length_password_equal_or_more_5 = true;
   }
   return english_symbols & length_password_equal_or_more_5 & is_spec_symbols & is_numbers & is_upper_symbols;
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

QString clients_func::random_password() {
   using milliseconds = std::chrono::duration<unsigned long long, std::ratio<1,1000>>;
   QRandomGenerator object(std::chrono::duration_cast<milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count());

   int random_length = object.bounded(7, 16);
   QString symbols = QString("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!\"#%&'()*+,-./:;<=>?@[\\]^_`{}");
    QString upper_symbols = QString("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    QString lower_symbols = QString("abcdefghijklmnopqrstuvwxyz");
    QString digits = QString("0123456789");
    QString special_symbols = QString("!\"#%&'()*+,-./:;<=>?@[\\]^_`{}");

    // Генерация обязательных символов для пароля
    QString random_pswd;
    int random_count = object.bounded(0, random_length / 5 + 1);
    for (int i = 0; i < random_count; i++ ) {
      random_pswd.append(upper_symbols[object.bounded(0, upper_symbols.length())]);
      random_pswd.append(lower_symbols[object.bounded(0, lower_symbols.length())]);
      random_pswd.append(digits[object.bounded(0, digits.length())]);
      random_pswd.append(special_symbols[object.bounded(0, special_symbols.length())]);
    }

    // Дополняем пароль случайными символами из всего набора
    for (int i = 0; i < (random_length - random_count * 4); i++) {
        random_pswd.append(symbols[object.bounded(0, symbols.length())]);
    }

    // Перемешиваем символы в пароле, чтобы распределить их случайным образом
    std::random_shuffle(random_pswd.begin(), random_pswd.end());

    return random_pswd;
}

void clients_func::equation(QHBoxLayout* uravnenie, action effect){ // функция, которая прячет/показывает макет уравнений
   if (effect == action::HIDE) {
      for (int i = 0; i < uravnenie->count(); i++) {
         uravnenie->itemAt(i)->widget()->hide(); // прячем виджеты layout'a
      }
   }
   else if (effect == action::SHOW) {
      for (int i = 0; i < uravnenie->count(); i++) {
         uravnenie->itemAt(i)->widget()->show(); // показываем виджеты layout'a
      }
   }
}
QString clients_func::create_hash(QString text)
{
   return QCryptographicHash::hash(text.toUtf8(), QCryptographicHash::Algorithm::Sha256).toHex();
}

int clients_func::random_code() { // генерируем случайный код.
   QRandomGenerator generate_random_code(QTime::currentTime().msec());
   int random_code = generate_random_code.bounded(1000, 9999 + 1);
   return random_code; // генерируем случайный код
}

