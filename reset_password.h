#ifndef RESET_PASSWORD_H
#define RESET_PASSWORD_H

#include <QWidget>
#include "Client.h"

class Widget; // класс окна регистрации
class auth_form; // класс окна авторизации

namespace Ui {
class reset_password;
}

class reset_password : public QWidget
{
   Q_OBJECT

public:
   explicit reset_password(Client* client, Widget* reg_window, auth_form* auth_window, QWidget *parent = nullptr);
   ~reset_password();

private slots:
   void on_pushButton_reset_password_clicked();

   void on_pushButton_to_reg_clicked();

   void on_pushButton_to_auth_clicked();

   void on_pushButton_code_clicked();

private:
   Ui::reset_password *ui;
   Client* client = nullptr;
   Widget* reg_window = nullptr;
   auth_form* auth_window = nullptr;
};

#endif // RESET_PASSWORD_H
