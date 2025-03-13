#ifndef RESET_PASSWORD_H
#define RESET_PASSWORD_H

#include <QWidget>
#include "Client.h"

class Widget;
class auth_form;

namespace Ui {
class reset_password;
}

class reset_password : public QWidget
{
   Q_OBJECT

public:
   explicit reset_password(Client* client, QWidget *parent = nullptr);
   Widget* window_reg = nullptr;
   auth_form* window_auth = nullptr;
   ~reset_password();

private slots:
   void on_pushButton_reset_password_clicked();

   void on_pushButton_to_reg_clicked();

   void on_pushButton_to_auth_clicked();

private:
   Ui::reset_password *ui;
   Client* client;
};

#endif // RESET_PASSWORD_H
