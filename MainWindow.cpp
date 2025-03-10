#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "clients_func.h"


Widget::Widget(QWidget *parent)
   : QWidget(parent)
   , ui(new Ui::Widget)
{
   ui->setupUi(this);
   QScreen *screen = QGuiApplication::primaryScreen();
   this->setGeometry((screen->availableGeometry().width() - screen->availableGeometry().width() / 2 ) / 2 , (screen->availableGeometry().height() - screen->availableGeometry().height() / 2) / 2, screen->availableGeometry().width() / 2, screen->availableGeometry().height() / 2);
   this->setWindowTitle(QString("Разработка приложения для поиска решения алгебраических уравнений вида x = y(x) методом половинного деления"));
   ui->label_wrong_login->hide();
   ui->label_wrong_password->hide();
   ui->label_wrong_email->hide();
   this->setLayout(ui->gridLayout_2);
   this->show();
}
Widget::~Widget()
{
   delete ui;
}



void Widget::on_pushButton_reg_clicked()
{
   if (clients_func::current_login(ui->lineEdit_login->text())) {
      ui->label_wrong_login->hide();
      qDebug() << "login correct";
   }
   else {
      ui->label_wrong_login->show();
      qDebug() << "login iscorrect";
   }

   if(clients_func::current_password(ui->lineEdit_password->text())) {
      ui->label_wrong_password->hide();
      qDebug() << "password correct";
   }
   else {
      ui->label_wrong_password->show();
      qDebug() << "password iscorrect!";
   }

   if (clients_func::current_email(ui->lineEdit_email->text())) {
      ui->label_wrong_email->hide();
      qDebug() << "email correct";
   }
   else {
      ui->label_wrong_email->show();
      qDebug() << "email iscorrect!";
   }

}

