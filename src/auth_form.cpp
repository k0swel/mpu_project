#include "auth_form.h"
#include "ui_auth_form.h"
#include "clients_func.h"
#include "client_main_window.h"
#include "reset_password.h"
#include "reg_form.h"
#include <QMessageBox>
#include "notification.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <fstream>
#include <filesystem>

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
   this->fill_from_json();
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
      clients_func::create_messagebox("Предупреждение об ошибке", "Вы ввели логин в некорректном формате.\n\nЛогин должен содержать следующие символы: A-Z ; a-z; 0-9;\n спец.символы(кроме $ и | )", clients_func::dialog_style::NO_BTN);
   }
   if (!current_password) { // если мы ввели некорректный пароль
      clients_func::create_messagebox("Предупреждение об ошибке", "Вы ввели пароль в некорректном формате.\n\nПароль должен содержать следующие символы: A-Z ; a-z; 0-9;\n спец.символы(кроме $ и | ) и длина не меньше 5 символов.", clients_func::dialog_style::NO_BTN);
   }

   if (current_login and current_password) { // если мы ввели  логин и пароль в правильном формате
      QString login = ui->lineEdit_login->text(); // получаем логин из виджета ввода.
      QString password = ui->lineEdit_password->text(); // получаем пароль из виджета ввода.
      QString hash_password = clients_func::create_hash(password); // хэшируем пароль.
      qDebug() << "Расшифрованный хэш: " << hash_password;
      QString final_data = QString("login|%1$%2").arg(login).arg(hash_password); // объединяем логин и пароль в строку, которую отправим на сервер
      client->write(final_data);
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
   if (ui->checkBox_remamber_me->isChecked()) {
      if (ui->checkBox_remamber_me->isChecked()) {
         this->write_info_in_cache();
         qDebug() << "Данные записаны";
      }
   }
   this->hide(); // прячем окно
   new client_main_window(this->client); // открываем окно клиента.
   this->close(); // закрываем текущее окно
}

void auth_form::auth_error() {
   notification::create_instance("Ошибка", AUTH_ERROR); // показываем уведомление с ошибкой.
}



void auth_form::on_pushButton_draw_password_pressed() // функция показывает введенный пароль при нажатии кнопки
{
   ui->lineEdit_password->setEchoMode(QLineEdit::EchoMode::Normal); // при зажатии на кнопку показываем введенный нами пароль.

}


void auth_form::on_pushButton_draw_password_released()
{
   ui->lineEdit_password->setEchoMode(QLineEdit::EchoMode::Password); // при отпускании кнопки обратно прячем пароль

}

void auth_form::write_info_in_cache() // функция для записи данных пользователя в JSON-файл
{
   // СОЗДАЁМ JSON КУДА БУДЕМ ЗАПИСЫВАТЬ ДАННЫЕ ОТ АККАУНТА
   QString login = ui->lineEdit_login->text(); // login
   QString password = ui->lineEdit_password->text(); // password;
   QJsonObject main_object;
   main_object["login"] = QJsonValue(login);
   main_object["password"] = QJsonValue(password);
   QJsonDocument json_doc;
   json_doc.setObject(main_object);

   if (std::filesystem::create_directory("./cache")) {
      qDebug() << "Директория успешно создана";
   }
   else {
      qDebug() << "Ошибка! Вероятно директория уже существует";
   }

   std::fstream json_file;
   json_file.open("cache/auth_data.json", std::ios_base::out); // открываем файл чтобы записать туда JSON
   if (json_file.is_open()) {
      json_file.write(json_doc.toJson(), json_doc.toJson().size()); // записываем json в файл
      notification::create_instance("Успех", "Ваши данные записаны!");
      json_file.close();
   }
   else {
      notification::create_instance("Ошибка", "Непредвиденная ошибка при попытке записи JSON-файла");
   }

}

void auth_form::fill_from_json() {
   QJsonDocument json_data;
   std::fstream json_file;
   std::string lines_from_file;

   // считываем данные из JSON-файла в переменную QJsonDocument json_data
   json_file.open("cache/auth_data.json", std::ios_base::in);
   if (json_file.is_open()) {
      qDebug() << "json file успешно открыт";
      std::string line_from_file;
      while (std::getline(json_file, line_from_file)) {
         lines_from_file += line_from_file;
      }
      json_data= QJsonDocument::fromJson(QByteArray(lines_from_file.c_str()));
      qDebug().noquote() << json_data.toJson();
   }
   else {
      qDebug() << "Ошибка при открытии json-файла";
      return;
   }

   //Заполняем поля ввода значениями из QJsonDocument
   ui->lineEdit_login->setText(json_data.object()["login"].toString());
   ui->lineEdit_password->setText(json_data.object()["password"].toString());
}

