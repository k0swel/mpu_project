#ifndef AUTH_FORM_H
#define AUTH_FORM_H

#include <QWidget>
#include "client.h"

class reset_password; // класс окна сброса пароля
class Widget; // класс окна регистрации
class client_main_window; // класс окна клиента

namespace Ui {
class auth_form;
}

class auth_form : public QWidget
{
   Q_OBJECT

public:
   explicit auth_form(Client* client_socket, Widget* reg_window, QWidget *parent = nullptr);
   ~auth_form();

private slots:
   void on_pushButton_login_clicked();

   void on_pushButton_reset_password_clicked();

   void on_pushButton_to_reg_clicked();

private:
   Ui::auth_form *ui;
   Client* client = nullptr;
   Widget* reg_window = nullptr;
   reset_password* window_reset = nullptr;
   client_main_window* client_window = nullptr;
};

#endif // AUTH_FORM_H
