#ifndef CLIENTS_FUNC_H
#define CLIENTS_FUNC_H
#include <QString>
#include <QDate>
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
   static bool current_login(QString login);
   static bool current_password(QString password);
   static bool current_email(QString email);
   static QString get_client_time();
   static QString random_password();
   static int random_code();
   static void equation(QHBoxLayout* uravnenie, action effect);
   static bool correct_digitals(QHBoxLayout* uravnenie);
   static QString create_hash(QString text);
private:
   static bool english_symbols(QString text);
};

#endif // CLIENTS_FUNC_H
