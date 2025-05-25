#ifndef CLIENTS_FUNC_H
#define CLIENTS_FUNC_H
#include <QString>
#include <QDate>
#include <QMessageBox>
#include <QHBoxLayout>

enum class action {
  HIDE,
   SHOW,
};

class clients_func
{
private:
   clients_func() = delete;
   clients_func(const clients_func&) = delete;
   ~clients_func() = delete;

public:
   static bool current_login(QString login); // проверка логина на корректность
   static bool current_password(QString password); // проверка пароля на корректность
   static bool current_email(QString email); // проверка email на корректность
   static QString get_client_time(); // получить клиентские время
   static QString random_password(); // генерация случайного пароля
   static int random_code(); // генерация случайного кода
   static void equation(QHBoxLayout* uravnenie, action effect); // спрятать или показать уравнение
   static QString create_hash(QString text); // создать хэш пароля
   enum class dialog_return_button { // enum для возвращаемого значения функции create_messagebox
      BTN_YES,
      BTN_NO,
      NULL_VALUE,
   };

   enum class dialog_style { // стиль диалога (с кнопками или без кнопок)
      WITH_BTN,
      NO_BTN,
   };
   static dialog_return_button create_messagebox(QString title, QString message, dialog_style style); // функция для генерации QMessageBox
private:
   static bool english_symbols(QString text);
};

#endif // CLIENTS_FUNC_H
