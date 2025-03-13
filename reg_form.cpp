#include "reg_form.h"
#include "ui_reg_form.h"
#include "clients_func.h"
#include "auth_form.h"
#include <QTimer>


Widget::Widget(Client* Client, QWidget *parent)
   : QWidget(parent)
   , ui(new Ui::Widget),
     client(Client)
{
   ui->setupUi(this);
   this->setWindowTitle(QString("Регистрация"));
   this->setWindowFlags(Qt::MSWindowsFixedSizeDialogHint); // нельзя сменить размер окна мышкой или клавой
   ui->dateEdit_birthday->setMaximumDate(QDate::currentDate()); // устанавливаем максимальную дату - сегодняшний день
   this->setWindowOpacity(0.95); // делаем окно немного прозрачным
   this->reset_text(); // сбрасываем сообщения об ошибках ввода логина пароля и почты.
   this->show();
}
Widget::~Widget()
{
   delete ui;
}



void Widget::on_pushButton_reg_clicked()
{
   QString login = ui->lineEdit_login->text();
   QString password = ui->lineEdit_password->text();
   QString email = ui->lineEdit_email->text();
   int year_of_birthday, month_of_birthday, day_of_birthday; // год, месяц и день рождения клиента.
   ui->dateEdit_birthday->date().getDate(&year_of_birthday, &month_of_birthday, &day_of_birthday);

   bool current_login = clients_func::current_login(login);
   bool current_password = clients_func::current_password(password);
   bool current_email = clients_func::current_email(email);

   if (current_login) // если мы ввели корректный логин и пароль
      ui->label_wrong_login->hide();

   if (current_password)
      ui->label_wrong_password->hide();

   if (current_email)
      ui->label_wrong_email->hide();

   if (!current_login)
      ui->label_wrong_login->show();

   if (!current_password)
      ui->label_wrong_password->show();

   if (!current_email)
      ui->label_wrong_email->show();

   if (current_login and current_password and current_email) {
      ui->label_wrong_login->hide();
      ui->label_wrong_password->hide();
      QString final_data = QString("reg | %1$%2$%3$%4-%5-%6").arg(login).arg(password).arg(email).arg(year_of_birthday).arg(month_of_birthday).arg(day_of_birthday);
      client->write(final_data.toUtf8());
   }

}


void Widget::on_toolButton_auth_clicked()
{
   this->close();
   if (this->window_auth == nullptr) {
      this->window_auth = new auth_form(client);
      this->window_auth->window_reg = this;
   }
   this->reset_text(); // сбрасываем сообщения об ошибках.
   this->window_auth->show();
}

void Widget::reset_text() { // сбрасываем сообщения об ошибках: неверный логин, пароль итд.
   ui->label_wrong_login->hide();
   ui->label_wrong_password->hide();
   ui->label_wrong_email->hide();
}

