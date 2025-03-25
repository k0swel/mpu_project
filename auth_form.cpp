#include "auth_form.h"
#include "ui_auth_form.h"
#include "clients_func.h"
#include "reset_password.h"
#include "reg_form.h"
#include <QMessageBox>

auth_form::auth_form(Client* client_socket, QWidget *parent) :
   QWidget(parent),
   ui(new Ui::auth_form),
   client(client_socket)
{
   ui->setupUi(this);
   this->setWindowTitle(QString("Метод половинного деления"));
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

   if (!current_login) { // если мы ввели некорректный логин
      QMessageBox::information(this, "Предупреждение об ошибке", "Вы ввели логин в некорректном формате.\n\nЛогин должен содержать следующие символы: A-Z ; a-z; 0-9;\n спец.символы(кроме $ и | )");
   }
   if (!current_password) { // если мы ввели некорректный пароль
      QMessageBox::information(this, "Предупреждение об ошибке", "Вы ввели пароль в некорректном формате.\n\nПароль должен содержать следующие символы: A-Z ; a-z; 0-9;\n спец.символы(кроме $ и | ) и длина не меньше 5 символов.");
   }

   if (current_login and current_password) { // если мы ввели корректный логин и пароль
      QString login = ui->lineEdit_login->text();
      QString password = ui->lineEdit_password->text();
      QString final_data = QString("login | %1$%2").arg(login).arg(password);
      client->write(final_data.toUtf8());
   }

}


void auth_form::on_pushButton_reset_password_clicked()
{
   this->close(); // закрываем окно.
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
   if (this->window_reset == nullptr) {
      window_reset = new reset_password(this->client);
      window_reset->window_auth = this;
      window_reset->window_reg = this->window_reg;
   }
   this->window_reg->show();
}

