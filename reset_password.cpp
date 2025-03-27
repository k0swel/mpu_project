#include "reset_password.h"
#include "ui_reset_password.h"
#include "clients_func.h"
#include <QMessageBox>
#include <QIntValidator>
// импортируем классы окна авторизации и регистрации:
#include "auth_form.h"
#include "reg_form.h"

reset_password::reset_password(Client* client, Widget* reg_window, auth_form* auth_window, QWidget *parent) :
   QWidget(parent),
   ui(new Ui::reset_password),
   reg_window(reg_window),
   auth_window(auth_window),
   client(client)
{
   ui->setupUi(this);
   ui->lineEdit_code->hide();
   ui->pushButton_code->hide();
   ui->label_code->hide();
   ui->pushButton_code->hide();
   ui->label_message_send_code->hide();

   ui->lineEdit_code->setValidator(new QIntValidator(0, 2147483647, this));
   this->setWindowFlag(Qt::MSWindowsFixedSizeDialogHint);
   this->setWindowTitle(QString("Метод половинного деления"));

   connect(this, &QWidget::destroyed, this, &QObject::deleteLater); // при закрытии окна, уничтожаем его из памяти.
}

reset_password::~reset_password()
{
   delete ui;
}

void reset_password::on_pushButton_reset_password_clicked()
{
   QString email = ui->lineEdit_email->text();
   if (clients_func::current_email(email) == true) { // если пользователь ввел корректный логин
      if (client->write(QString("reset|%1").arg(email).toUtf8())) {
         ui->pushButton_reset_password->hide();
         ui->pushButton_code->show();
         ui->lineEdit_code->show();
         ui->label_code->show();
      }
   }
   else {
      QMessageBox::information(nullptr, "Предупреждение об ошибке", "Вы ввели email в некорректном формате, попробуйте еще раз.");
      ui->lineEdit_email->setText("");
   }
}


void reset_password::on_pushButton_to_reg_clicked() // если нажата кнопка регистрации
{
   this->hide(); // закрываем текущее окно
   this->reg_window->show(); // открываем окно регистрации.
}


void reset_password::on_pushButton_to_auth_clicked() // если нажата кнопка авторизации
{
   this->hide(); // закрываем текущее окно
   this->auth_window->show(); // открываем окно авторизации.
}


void reset_password::on_pushButton_code_clicked()
{
   // ФУНКЦИЯ ДЛЯ ПОДТВЕРЖДЕНИЯ, ЧТО НА ПОЧТУ ПРИШЁЛ КОРРЕКТНЫЙ КОД.
}

