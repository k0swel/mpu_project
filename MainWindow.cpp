#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "clients_func.h"


Widget::Widget(QWidget *parent)
   : QWidget(parent)
   , ui(new Ui::Widget)
{
   ui->setupUi(this);
   QScreen *screen = QGuiApplication::primaryScreen();
   this->setGeometry(0, 0, screen->availableGeometry().width() / 4, screen->availableGeometry().height() / 4);
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
      qDebug() << "login correct";
   }
   else {
      qDebug() << "login iscorrect";
   }

   if(clients_func::current_password(ui->lineEdit_password->text())) {
      qDebug() << "password correct";
   }
   else {
      qDebug() << "password iscorrect!";
   }

   if (clients_func::current_email(ui->lineEdit_email->text())) {
      qDebug() << "email correct";
   }
   else {
      qDebug() << "email iscorrect!";
   }

}

