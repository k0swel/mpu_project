#ifndef CLIENTS_FUNC_H
#define CLIENTS_FUNC_H
#include <QString>
#include <QDate>

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
   static bool age(const QDate& date);
private:
   static bool english_symbols(QString text);
};

#endif // CLIENTS_FUNC_H
