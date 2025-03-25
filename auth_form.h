#ifndef AUTH_FORM_H
#define AUTH_FORM_H

#include <QWidget>
#include "client.h"

class reset_password;
class Widget;

namespace Ui {
class auth_form;
}

class auth_form : public QWidget
{
   Q_OBJECT

public:
   explicit auth_form(Client* client_socket, QWidget *parent = nullptr);
   Widget* window_reg = nullptr;
   reset_password* window_reset = nullptr;
   ~auth_form();

private slots:
   void on_pushButton_login_clicked();

   void on_pushButton_reset_password_clicked();

   void on_pushButton_to_reg_clicked();

private:
   Ui::auth_form *ui;
   Client* client;
};

#endif // AUTH_FORM_H
