#include "auth_form.h"
#include "ui_auth_form.h"
#include "clients_func.h"
#include "client_main_window.h"
#include "reset_password.h"
#include "reg_form.h"
#include <QMessageBox>
#include "notification.h"

#define AUTH_ERROR "Неверный логин/пароль"



auth_form::auth_form(Client* client_socket, QWidget *parent) :
   QWidget(parent),
   ui(new Ui::auth_form),
   client(client_socket)
{
   ui->setupUi(this);
   this->setWindowTitle(QString("Метод половинного деления"));
   this->setWindowFlag(Qt::MSWindowsFixedSizeDialogHint);
   this->ui->lineEdit_login->setFocus();
   this->setAttribute(Qt::WA_DeleteOnClose); // удаляем окно при нажатии на значок закрытия.
   connect(this->client, &Client::auth_ok, this, &auth_form::auth_ok); // сигнал на случай успешной авторизации
   connect(this->client, &Client::auth_error, this, &auth_form::auth_error); // сигнал на случай ошибки при авторизации
   ui->pushButton_draw_password->setFixedSize(QSize(20,ui->pushButton_draw_password->height()));
   this->show(); // показываем текущее окно.
}

auth_form::~auth_form()
{
   disconnect(this->client, &Client::auth_ok, this, &auth_form::auth_ok); // отмена сигнала на случай успешной авторизации
   disconnect(this->client, &Client::auth_error, this, &auth_form::auth_error); // отмена сигнала на случай ошибки при авторизации
   qDebug() << "Вызвался деструктор окна авторизации";
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
      QString hash_password = clients_func::create_hash(password); // хэшируем пароль.
      QString final_data = QString("login|%1$%2").arg(login).arg(hash_password); // объединяем логин и пароль в строку, которую отправим на сервер
      if (client->write(final_data)) { // отправляем введенные пользователем данные на сервер.
         if (true) { // если ответ от сервера положительный, то впускаем клиента на сервер
            // ДОБАВЛЕН CONNECT НА СЛУЧАЙ УСПЕШНОЙ АВТОРИЗАЦИИ
         }
         else {
            // ДОБАВЛЕН CONNECT НА СЛУЧАЙ ОШИБКИ ПРИ АВТОРИЗАЦИИ
         }
      }
   }
}


void auth_form::on_pushButton_reset_password_clicked() // нажата кнопка вызова окна сброса пароля
{
   this->hide(); // закрываем текущее окно.
   new reset_password(this->client); // создаём окно сброса пароля
   this->close(); // закрываем текущее окно
}


void auth_form::on_pushButton_to_reg_clicked() // нажата кнопка вызова окна регистрации
{
   this->hide(); // закрываем текущее окно.
   new Widget(this->client); // создаём окно регистрации.
   this->close(); // закрываем текущее окно.
}

void auth_form::auth_ok() {
   this->hide(); // прячем окно
   new client_main_window(this->client); // открываем окно клиента.
   this->close(); // закрываем текущее окно
}

void auth_form::auth_error() {
   new notification("Ошибка", AUTH_ERROR); // показываем уведомление с ошибкой.
}



void auth_form::on_pushButton_draw_password_pressed() // функция показывает введенный пароль при нажатии кнопки
{
   ui->lineEdit_password->setEchoMode(QLineEdit::EchoMode::Normal); // при зажатии на кнопку показываем введенный нами пароль.

}


void auth_form::on_pushButton_draw_password_released()
{
   ui->lineEdit_password->setEchoMode(QLineEdit::EchoMode::Password); // при отпускании кнопки обратно прячем пароль

}

