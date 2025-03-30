#include "reset_password.h"
#include "ui_reset_password.h"
#include "clients_func.h"
#include <QMessageBox>
#include <QIntValidator>
// импортируем классы окна авторизации и регистрации:
#include "auth_form.h"
#include "reg_form.h"
#include "client.h"


reset_password::reset_password(Client* client, QWidget *parent) :
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

   ui->lineEdit_code->setValidator(new QIntValidator(0, 2147483647, this));
   this->setWindowFlag(Qt::MSWindowsFixedSizeDialogHint);
   this->setWindowTitle(QString("Метод половинного деления"));
   this->setAttribute(Qt::WA_DeleteOnClose); // удаляем окно при нажатии на значок закрытия.
   this->show(); // показываем текущее окно.
}

reset_password::~reset_password()
{
   qDebug() << "Вызвался деструктор окна сброса пароля";
   delete ui;
}

void reset_password::on_pushButton_reset_password_clicked()
{
   QString email = ui->lineEdit_email->text();
   if (clients_func::current_email(email) == true) { // если пользователь ввел корректный email
      this->generate_code = clients_func::random_code(); // генерируем случайный код
      if (client->write(QString("reset|%1$%2").arg(email).arg(this->generate_code))) {
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
   this->hide(); // закрываем текущее окно.
   new Widget(this->client); // создаём окно регистрации.
   this->close(); // закрываем текущее окно.
}


void reset_password::on_pushButton_to_auth_clicked() // если нажата кнопка авторизации
{
   this->hide(); // прячем текущее окно.
   new auth_form(this->client); // создаём окно авторизации.
   this->close(); // закрываем текущее окно.
}


void reset_password::on_pushButton_code_clicked() // если нажата кнопка отпаравки кода
{
   if (ui->lineEdit_code->text().toInt() == this->generate_code) {
      QString new_password = clients_func::random_password();
      this->client->write(QString("new_password|%1$%2").arg(ui->lineEdit_email->text()).arg(new_password));
      QMessageBox::information(this, QString("Обновление пароля"), QString("Вот ваш новый сгенерированный пароль: %1").arg(new_password));
      this->hide(); // прячем текущее окно
      new auth_form(this->client); // создаём окно авторизации.
      this->close(); // закрываем текущее окно
   }
   else {
      QMessageBox::information(this, "Ошибка", "Вы ввели неверный код. Попробуйте ещё раз");
   }
}

