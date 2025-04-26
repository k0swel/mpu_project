#include "reset_password.h"
#include "ui_reset_password.h"
#include "clients_func.h"
#include <QMessageBox>
#include <QIntValidator>
// импортируем классы окна авторизации и регистрации:
#include "auth_form.h"
#include "reg_form.h"
#include "client.h"
#include "notification.h"

reset_password::reset_password(Client* client, QWidget *parent) :
   QWidget(parent),
   ui(new Ui::reset_password),
   client(client)
{
   ui->setupUi(this);
   ui->lineEdit_code->hide(); // прячем lineedit ввода кода
   ui->pushButton_code->hide(); // прячем pushbutton отправки кода
   ui->label_code->hide(); // прячем label код
   ui->pushButton_code->hide(); // прячем pushbutton код
   ui->label_message_send_code->hide(); // прячем сообщение об отправки кода на почту

   connect(this->client, &Client::reset_error, this, &reset_password::slot_reset_error);

   ui->lineEdit_code->setValidator(new QIntValidator(0, 2147483647, this)); // устанавливаем допустимый диапозон кода
   this->setWindowFlag(Qt::MSWindowsFixedSizeDialogHint); // запрещаем изменять размер окна
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
   QString login = ui->lineEdit_login->text();
   if (!login.isEmpty()) {// если мы заполнили чем-то поле логина
      this->generate_code = clients_func::random_code(); // генерируем случайный код
      this->ui->lineEdit_login->setEnabled(false); // делаем неактивным поле логина.
      if (client->write(QString("reset|%1$%2").arg(login).arg(this->generate_code))) {
         qDebug() << "Сгенерированный код: " << this->generate_code;
         ui->pushButton_reset_password->hide();
         ui->pushButton_code->show();
         ui->lineEdit_code->show();
         ui->label_code->show();
      }
   }
   else {
      new notification("Ошибка", "Заполните поле ""Логин"". Оно не должно быть пустым!");
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


void reset_password::on_pushButton_code_clicked() // если нажата кнопка отправки кода
{
   if (ui->lineEdit_code->text().toInt() == this->generate_code) {
      QString new_password = clients_func::random_password(); // генерируем новый пароль для клиента
      QString hash_new_password = clients_func::create_hash(new_password); // хэшируем новый пароль
      this->client->write(QString("new_password|%1$%2").arg(ui->lineEdit_login->text()).arg(hash_new_password));
      clients_func::create_messagebox("Обновление пароля", QString("Ваш новый пароль: %1").arg(new_password));
      this->hide(); // прячем текущее окно
      new auth_form(this->client); // создаём окно авторизации.
      this->close(); // закрываем текущее окно
   }
   else {
      clients_func::create_messagebox(QString("Ошибка"), QString("Вы ввели некорректный код. Попробуйте ещё раз"));
   }
}

void reset_password::slot_reset_error()
{
   ui->pushButton_reset_password->show(); // делаем активным кнопку сброса пароля.
   ui->pushButton_code->hide(); // прячем кнопку отправки кода.
   ui->lineEdit_code->hide(); // прячем lineedit ввода кода.
   ui->label_code->hide(); // прячемт текст, относящийся к коду.
   new notification("Ошибка", "Пользователя с указанным логином не существует. Попробуйте зарегистрироваться."); // уведомление о том, что пользователя с указанным логином не существует
}


void reset_password::on_pushButton_clicked()
{
   ui->lineEdit_login->setText(QString("")); // устанавливаем пустой текст в поле ввода логина.
   ui->lineEdit_code->setText(QString("")); // устанавливаем пустой текст в поле ввода кода.
   ui->lineEdit_login->setEnabled(true); // активируем поле ввода логина.
   ui->lineEdit_code->hide(); // прячем lineedit ввода кода
   ui->pushButton_code->hide(); // прячем pushbutton отправки кода
   ui->label_code->hide(); // прячем label код
   ui->pushButton_code->hide(); // прячем pushbutton код
   ui->label_message_send_code->hide(); // прячем сообщение об отправки кода на почту
   ui->pushButton_reset_password->show(); // показываем кнопку "Забыл пароль".
}

