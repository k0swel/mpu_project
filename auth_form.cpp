#include "auth_form.h"
#include "ui_auth_form.h"
#include "clients_func.h"

auth_form::auth_form(Client* client_socket, QWidget *parent) :
   QWidget(parent),
   ui(new Ui::auth_form),
   client(client_socket)
{
   ui->setupUi(this);
   ui->label_wrong_login->hide();
   ui->label_wrong_password->hide();
}

auth_form::~auth_form()
{
   delete ui;
}

void auth_form::on_pushButton_login_clicked()
{
   bool current_login = clients_func::current_login(ui->lineEdit_login->text());
   bool current_password = clients_func::current_password(ui->lineEdit_password->text());

   if (current_login) { // если мы ввели корректный логин и пароль
      ui->label_wrong_login->hide();
   }
   if (current_password) {
      ui->label_wrong_password->hide();
   }
   if (!current_login) {
      ui->label_wrong_login->show();
   }
   if (!current_password) {
      ui->label_wrong_password->show();
   }

   if (current_login and current_password) {
      ui->label_wrong_login->hide();
      ui->label_wrong_password->hide();
      QString login = ui->lineEdit_login->text();
      QString password = ui->lineEdit_password->text();
      QString final_data = QString("login | %1$%2").arg(login).arg(password);
      client->write(final_data.toUtf8());
   }

}

