#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "clients_func.h"
#include "auth_form.h"


Widget::Widget(Client* Client, QWidget *parent)
   : QWidget(parent)
   , ui(new Ui::Widget),
     client(Client)
{
   ui->setupUi(this);
   QScreen *screen = QGuiApplication::primaryScreen();
   this->setGeometry((screen->availableGeometry().width() - screen->availableGeometry().width() / 2 ) / 2 , (screen->availableGeometry().height() - screen->availableGeometry().height() / 2) / 2, screen->availableGeometry().width() / 2, screen->availableGeometry().height() / 2);
   this->setWindowTitle(QString("Разработка приложения для поиска решения алгебраических уравнений вида x = y(x) методом половинного деления"));
   ui->label_wrong_login->hide();
   ui->label_wrong_password->hide();
   ui->label_wrong_email->hide();
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
      QString final_data = QString("reg | %1$%2$%3").arg(login).arg(password).arg(email);
      client->write(final_data.toUtf8());
   }

}


void Widget::on_toolButton_auth_clicked()
{
   this->hide();
   if (authorization == nullptr)
      authorization = new auth_form(client);
   authorization->show();
}

