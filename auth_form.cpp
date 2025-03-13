#include "auth_form.h"
#include "ui_auth_form.h"
#include "clients_func.h"
#include "reset_password.h"
#include "reg_form.h"

auth_form::auth_form(Client* client_socket, QWidget *parent) :
   QWidget(parent),
   ui(new Ui::auth_form),
   client(client_socket)
{
   ui->setupUi(this);
   ui->label_wrong_login->hide(); // скрываем сообщение о неверном логине
   ui->label_wrong_password->hide(); // скрываем сообщение о неверном пароле
   this->setWindowTitle(QString("Авторизация"));
   this->setWindowFlag(Qt::MSWindowsFixedSizeDialogHint);
}

auth_form::~auth_form()
{
   delete ui;
}

void auth_form::on_pushButton_login_clicked()
{
   bool current_login = clients_func::current_login(ui->lineEdit_login->text());
   bool current_password = clients_func::current_password(ui->lineEdit_password->text());

   if (current_login) { // если мы ввели корректный логин
      ui->label_wrong_login->hide();
   }
   if (current_password) { // если мы ввели корректный пароль
      ui->label_wrong_password->hide();
   }
   if (!current_login) { // если мы ввели некорректный логин
      ui->label_wrong_login->show();
   }
   if (!current_password) { // если мы ввели некорректный пароль
      ui->label_wrong_password->show();
   }

   if (current_login and current_password) { // если мы ввели корректный логин и пароль
      ui->label_wrong_login->hide();
      ui->label_wrong_password->hide();
      QString login = ui->lineEdit_login->text();
      QString password = ui->lineEdit_password->text();
      QString final_data = QString("login | %1$%2").arg(login).arg(password);
      client->write(final_data.toUtf8());
   }

}


void auth_form::on_pushButton_reset_password_clicked()
{
   this->close(); // закрываем окно.
   this->reset_text(); // скрываем сообщения об ошибках при вводе логина/пароля
   if (this->window_reset == nullptr) {
      window_reset = new reset_password(this->client);
      window_reset->window_auth = this;
      window_reset->window_reg = this->window_reg;
   }
   window_reset->show();

}


void auth_form::on_pushButton_to_reg_clicked()
{
   this->close();
   this->reset_text();
   if (this->window_reset == nullptr) {
      window_reset = new reset_password(this->client);
      window_reset->window_auth = this;
      window_reset->window_reg = this->window_reg;
   }
   this->window_reg->show();
}

void auth_form::reset_text() { // прячем сообщения о некорректных логина и пароля
   ui->label_wrong_login->hide(); // неверный логин
   ui->label_wrong_password->hide(); // неверный пароль
}

