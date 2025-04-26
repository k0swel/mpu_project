#ifndef RESET_PASSWORD_H
#define RESET_PASSWORD_H

#include <QWidget>
#include "client.h"
#include <QCloseEvent>
#include <QMessageBox>
#include <QThread>


class Widget; // класс окна регистрации
class auth_form; // класс окна авторизации

namespace Ui {
class reset_password;
}

class reset_password : public QWidget
{
   Q_OBJECT

public:
   explicit reset_password(Client* client, QWidget *parent = nullptr);
   ~reset_password();

private slots:
   void on_pushButton_reset_password_clicked();

   void on_pushButton_to_reg_clicked();

   void on_pushButton_to_auth_clicked();

   void on_pushButton_code_clicked();

   void slot_reset_error();

   void on_pushButton_clicked();

private:
   Ui::reset_password *ui;
   Client* client = nullptr;
   int generate_code; // переменная хранит сгенерированный код подтверждения.
};

#endif // RESET_PASSWORD_H
