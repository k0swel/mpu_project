#include "auth_form.h"
#include "ui_auth_form.h"
#include "clients_func.h"

#include "client_main_window.h"
#include "reset_password.h"
#include "reg_form.h"
#include <QMessageBox>

auth_form::auth_form(Client* client_socket, Widget* reg_window, QWidget *parent) :
   QWidget(parent),
   ui(new Ui::auth_form),
   client(client_socket),
   reg_window(reg_window)
{
   ui->setupUi(this);
   this->setWindowTitle(QString("Метод половинного деления"));
   this->setWindowFlag(Qt::MSWindowsFixedSizeDialogHint);

   connect(this, &QWidget::destroyed, this, &QObject::deleteLater); // при закрытии окна, уничтожаем его из памяти.

}

auth_form::~auth_form()
{
   delete ui;
}

void auth_form::on_pushButton_login_clicked() // нажата кнопка авторизации
{
   bool current_login = clients_func::current_login(ui->lineEdit_login->text());
   bool current_password = clients_func::current_password(ui->lineEdit_password->text());

   if (!current_login) { // если мы ввели некорректный логин
      QMessageBox::information(this, "Предупреждение об ошибке", "Вы ввели логин в некорректном формате.\n\nЛогин должен содержать следующие символы: A-Z ; a-z; 0-9;\n спец.символы(кроме $ и | )");
   }
   if (!current_password) { // если мы ввели некорректный пароль
      QMessageBox::information(this, "Предупреждение об ошибке", "Вы ввели пароль в некорректном формате.\n\nПароль должен содержать следующие символы: A-Z ; a-z; 0-9;\n спец.символы(кроме $ и | ) и длина не меньше 5 символов.");
   }

   if (current_login and current_password) { // если мы ввели  логин и пароль в правильном формате
      QString login = ui->lineEdit_login->text(); // получаем логин из виджета ввода.
      QString password = ui->lineEdit_password->text(); // получаем пароль из виджета ввода.
      QString final_data = QString("login|%1$%2").arg(login).arg(password); // объединяем логин и пароль в строку, которую отправим на сервер
      client->write(final_data.toUtf8()); // отправляем введенные пользователем данные на сервер.
      if (true) { // если ответ от сервера положительный, то впускаем клиента на сервер
         this->hide(); // скрываем текущее окно
         if (this->client_window == nullptr) { // если окно клиента не создано
            this->client_window = new client_main_window(this->client, this->reg_window); // создаём
            this->client_window->show(); // показываем окно клиента
         }
         else {
            this->client_window->show();// показываем окно клиента
         }

      }
   }

}


void auth_form::on_pushButton_reset_password_clicked() // нажата кнопка вызова окна сброса пароля
{
   this->hide(); // закрываем текущее окно.
   if (this->window_reset == nullptr) { // если объект окна сброса пароля не создан
      window_reset = new reset_password(this->client, this->reg_window, this); // создаём объект окна сброса пароля
      window_reset->show(); // показываем окно сброса пароля.
   }
   else {
      window_reset->show(); // показываем окно сброса пароля.
   }

}


void auth_form::on_pushButton_to_reg_clicked() // нажата кнопка вызова окна регистрации
{
   this->hide(); // закрываем текущее окно.
   this->reg_window->show(); // показываем окно регистрации
}

