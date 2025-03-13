#include "reset_password.h"
#include "ui_reset_password.h"
#include "clients_func.h"
#include <QMessageBox>
#include "auth_form.h"
#include "reg_form.h"
#include <QIntValidator>

reset_password::reset_password(Client* client,QWidget *parent) :
   QWidget(parent),
   ui(new Ui::reset_password),
   client(client)
{
   ui->setupUi(this);
   ui->lineEdit_code->hide();
   ui->pushButton_code->hide();
   ui->label_code->hide();
   ui->pushButton_code->hide();
   ui->label_message_send_code->hide();

   ui->lineEdit_code->setValidator(new QIntValidator(0, 2147483647));
   this->setWindowFlag(Qt::MSWindowsFixedSizeDialogHint);
   this->setWindowTitle(QString("Восстановление пароля"));
}

reset_password::~reset_password()
{
   delete ui;
}

void reset_password::on_pushButton_reset_password_clicked()
{
   QString email = ui->lineEdit_email->text();
   if (clients_func::current_email(email) == true) { // если пользователь ввел корректный логин
      client->write(QString("reset | %1").arg(email).toUtf8());
      ui->pushButton_reset_password->hide();
      ui->pushButton_code->show();
      ui->lineEdit_code->show();
      ui->label_code->show();
   }
   else {
      QMessageBox::information(nullptr, "Предупреждение об ошибке", "Вы ввели email в некорректном формате, попробуйте еще раз.");
      ui->lineEdit_email->setText("");
   }
}


void reset_password::on_pushButton_to_reg_clicked()
{
   this->close(); // закрываем текущее окно
   this->window_reg->show(); // открываем окно регистрации.
}


void reset_password::on_pushButton_to_auth_clicked()
{
   this->close();
   this->window_auth->show(); // открываем окно авторизации.
}

