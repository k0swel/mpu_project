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
   ui->dateEdit_birthday->setMaximumDate(QDate::currentDate()); // устанавливаем максимальную дату - сегодняшний день
   ui->dateEdit_birthday->setDate(QDate::currentDate()); // устанавливаем виджет даты рождения - текущий день.
   this->setAttribute(Qt::WA_DeleteOnClose); // удаляем окно при нажатии на значок закрытия.
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
   bool current_age = clients_func::age(ui->dateEdit_birthday->date());
   bool is_empty_name = ui->lineEdit_name->text().isEmpty(); // проверяем пустой ли виджет ввода имени
   bool is_empty_last_name = ui->lineEdit_lastname->text().isEmpty(); // проверяем пустой ли виджет ввода фамилии
   if (!current_login) // если мы ввели некорректный логин пароль или email
      QMessageBox::information(this, "Предупреждение об ошибке", "Вы ввели логин в некорректном формате.\n\nЛогин должен содержать следующие символы: A-Z ; a-z; 0-9;\n спец.символы(кроме $ и | )");

   if (!current_password)
      QMessageBox::information(this, "Предупреждение об ошибке", "Вы ввели пароль в некорректном формате.\n\nПароль должен содержать следующие символы: A-Z ; a-z; 0-9;\n спец.символы(кроме $ и | ) и длина не меньше 5 символов.");

   if (!current_email)
      QMessageBox::information(this, "Предупреждение об ошибке", "Вы ввели почту в некорректном формате.\n\n Почта должна содержать следующие символы: A-Z ; a-z; 0-9;\n спец.символы(кроме $ и | ).\n\nЛокальная часть почты не должна начинаться с \".\" и доменная часть почты не должна иметь более двух точек.");

   if (!current_age)
      QMessageBox::information(this, "Предупреждение об ошибке", "Требуемый возраст - 12 лет");
   if (is_empty_name)
       QMessageBox::information(this, "Предупреждение об ошибке", "Введите своё имя!");
   if (is_empty_last_name)
       QMessageBox::information(this, "Предупреждение об ошибке", "Введите свою фамилию");
   if (current_login and current_password and current_email and current_age and !is_empty_name and !is_empty_last_name) {
       QString final_data = QString("reg|%1$%2$%3$%4-%5-%6$%7$%8$%9").arg(login).arg(password).arg(email).arg(year_of_birthday).arg(month_of_birthday).arg(day_of_birthday).arg(ui->lineEdit_lastname->text()).arg(ui->lineEdit_name->text()).arg( ui->lineEdit_middlename->text());
       if (client->write(final_data.toUtf8())) {
          // ДОБАВЛЕН CONNECT НА СЛУЧАЙ ЕСЛИ РЕГИСТРАЦИЯ УСПЕШНА
       }
      else {
         // ДОБАВЛЕН СИГНАЛ НА СЛУЧАЙ ЕСЛИ ПОЛЬЗОВАТЕЛЬ УЖЕ ЗАРЕГИСТРИРОВАН
      }
   }
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
   new notification(REG_ERROR);
}


