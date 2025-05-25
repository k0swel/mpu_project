#include "reg_form.h"
#include "ui_reg_form.h"
#include "clients_func.h"
#include <QMessageBox>
#include "notification.h" // импорт окна уведомления
// импортируем классы окна авторизации и клиентского приложения
#include "auth_form.h"
#include "client_main_window.h"
#include "client.h"

#define REG_ERROR "Ошибка при регистрации. Данная учётная запись уже зарегистрирована"



Widget::Widget(Client* Client, QWidget *parent)
   : QWidget(parent)
   , ui(new Ui::Widget),
     client(Client)
{
   ui->setupUi(this);
   this->setWindowTitle(QString("Метод половинного деления"));
   this->setWindowFlags(Qt::MSWindowsFixedSizeDialogHint); // нельзя сменить размер окна мышкой или клавой
   this->setAttribute(Qt::WA_DeleteOnClose); // удаляем окно при нажатии на значок закрытия.
   this->ui->lineEdit_login->setFocus(); // устанавливаем фокус на ввод логина.
   connect(this->client, &Client::register_ok, this, &Widget::register_successful); // сигнал на случай успешной регистрации
   connect(this->client, &Client::register_error, this, &Widget::register_error); // сигнал на случай если пользователь уже зарегистрирован.
   this->show();
}
Widget::~Widget()
{
   disconnect(this->client, &Client::register_ok, this, &Widget::register_successful); // отмена сигнала об успешной регистрации.
   disconnect(this->client, &Client::register_error, this, &Widget::register_error); // отмена сигнала об ошибке при регистрации.
   qDebug() << "Вызвался деструктор окна регистрации";
   delete ui;
}


void Widget::on_toolButton_auth_clicked() // по нажатии на кнопку открываем окно авторизации
{
   this->hide(); // прячем текущее окно
   new auth_form(client); // создаём объект окна авторизации
   this->close(); // закрываем окно
}

void Widget::register_successful() {
   this->hide(); // прячем текущее окно.
   new client_main_window(this->client); // создаём объект клиентского окна
   this->close(); // закрываем текущее окно
}

void Widget::register_error() {
   notification::create_instance("Ошибка", REG_ERROR);
}



void Widget::on_pushButton_draw_password_pressed() // если зажата кнопка, то отображаем наш пароль
{
   ui->lineEdit_password->setEchoMode(QLineEdit::EchoMode::Normal); // при зажатии на кнопку показываем введенный нами пароль.

}


void Widget::on_pushButton_draw_password_released() // если отжата кнопка, то прячем наш пароль
{
   ui->lineEdit_password->setEchoMode(QLineEdit::EchoMode::Password); // при зажатии на кнопку показываем введенный нами пароль.

}


void Widget::on_pushButton_reg_clicked()
{
   QString login = ui->lineEdit_login->text(); // получаем логин из строки ввода
   QString password = ui->lineEdit_password->text(); // получаем пароль из строки ввода
   QString hash_password = clients_func::create_hash(password); // получем хэш пароля из ранее полученного пароля
   QString email = ui->lineEdit_email->text(); // получаем email из строки ввода email
   bool current_login = clients_func::current_login(login); // проверяем логин на корректность
   bool current_password = clients_func::current_password(password); // проверяем пароль на корректность
   bool current_email = clients_func::current_email(email); // проверяем emai на корректность
   bool is_empty_name = ui->lineEdit_name->text().isEmpty(); // проверяем пустой ли виджет ввода имени
   bool is_empty_last_name = ui->lineEdit_lastname->text().isEmpty(); // проверяем пустой ли виджет ввода фамилии
   if (!current_login) // если мы ввели некорректный логин пароль или email
      clients_func::create_messagebox("Предупреждение об ошибке", "Вы ввели логин в некорректном формате.\n\nЛогин должен содержать следующие символы: A-Z ; a-z; 0-9;\n спец.символы(кроме $ и | )",
                                      clients_func::dialog_style::NO_BTN);

   if (!current_password)
      clients_func::create_messagebox("Предупреждение об ошибке", "Вы ввели пароль в некорректном формате.\n\nПароль должен содержать следующие символы: A-Z ; a-z; 0-9;\n спец.символы(кроме $ и | ) и длина не меньше 5 символов.",
                                      clients_func::dialog_style::NO_BTN);

   if (!current_email)
      clients_func::create_messagebox("Предупреждение об ошибке", "Вы ввели почту в некорректном формате.\n\n Почта должна содержать следующие символы: A-Z ; a-z; 0-9;\n спец.символы(кроме $ и | ).\n\nЛокальная часть почты не должна начинаться с \".\" и доменная часть почты не должна иметь более двух точек.",
                                      clients_func::dialog_style::NO_BTN);

   if (is_empty_name)
       clients_func::create_messagebox("Предупреждение об ошибке", "Введите своё имя!", clients_func::dialog_style::NO_BTN);
   if (is_empty_last_name)
       clients_func::create_messagebox("Предупреждение об ошибке", "Введите свою фамилию", clients_func::dialog_style::NO_BTN);
   if (current_login and current_password and current_email and !is_empty_name and !is_empty_last_name) {
      QString final_data = QString("reg|%1$%2$%3$%4$%5$%6").arg(login).arg(hash_password).arg(email).arg(ui->lineEdit_lastname->text()).arg(ui->lineEdit_name->text()).arg(ui->lineEdit_middlename->text());
      client->write(final_data.toUtf8()); // отправляем данные серверу.
   }
}

