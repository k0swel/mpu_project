#include "reg_form.h"
#include "ui_reg_form.h"
#include "clients_func.h"
#include <QMessageBox>
// импортируем классы окна авторизации и клиентского приложения
#include "auth_form.h"
#include "client_main_window.h"

Widget::Widget(Client* Client, QWidget *parent)
   : QWidget(parent)
   , ui(new Ui::Widget),
     client(Client)
{
   ui->setupUi(this);
   this->setWindowTitle(QString("Метод половинного деления"));
   this->setWindowFlags(Qt::MSWindowsFixedSizeDialogHint); // нельзя сменить размер окна мышкой или клавой
   ui->dateEdit_birthday->setMaximumDate(QDate::currentDate()); // устанавливаем максимальную дату - сегодняшний день
   ui->dateEdit_birthday->setDate(QDate::currentDate());
   connect(this, &QWidget::destroyed, this, &QObject::deleteLater); // при закрытии окна, уничтожаем его из памяти.
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
   bool current_age = clients_func::age(ui->dateEdit_birthday->date());

   if (!current_login) // если мы ввели некорректный логин пароль или email
      QMessageBox::information(this, "Предупреждение об ошибке", "Вы ввели логин в некорректном формате.\n\nЛогин должен содержать следующие символы: A-Z ; a-z; 0-9;\n спец.символы(кроме $ и | )");

   if (!current_password)
      QMessageBox::information(this, "Предупреждение об ошибке", "Вы ввели пароль в некорректном формате.\n\nПароль должен содержать следующие символы: A-Z ; a-z; 0-9;\n спец.символы(кроме $ и | ) и длина не меньше 5 символов.");

   if (!current_email)
      QMessageBox::information(this, "Предупреждение об ошибке", "Вы ввели почту в некорректном формате.\n\n Почта должна содержать следующие символы: A-Z ; a-z; 0-9;\n спец.символы(кроме $ и | ).\n\nЛокальная часть почты не должна начинаться с \".\" и доменная часть почты не должна иметь более двух точек.");

   if (!current_age)
      QMessageBox::information(this, "Предупреждение об ошибке", "Требуемый возраст - 12 лет");

   if (current_login and current_password and current_email and current_age) {
      QString final_data = QString("reg|%1$%2$%3$%4-%5-%6").arg(login).arg(password).arg(email).arg(year_of_birthday).arg(month_of_birthday).arg(day_of_birthday);
      if (client->write(final_data.toUtf8())) {
         if (true) { // ЗДЕСЬ ВМЕСТО условия создадим connect, который ждёт сигнала от сервера, что пользователь успешно зарегистрирован.
            this->hide(); // закрываем текущее окно
            if (this->client_window == nullptr) { // если объект клиентского окна не создан
               this->client_window = new client_main_window(this->client,this); // создаём объект клиентского окна
               this->client_window->show(); // показываем основное клиетское окно
            }
            else {
               this->client_window->show(); // показываем основное клиетское окно
            }
         }
      }
   }

}


void Widget::on_toolButton_auth_clicked() // по нажатии на кнопку открываем окно авторизации
{
   this->close(); // закрываем текущее окно
   if (this->window_auth == nullptr) { // если объект окна авторизации не создан
      this->window_auth = new auth_form(client, this); // создаём объект окна авторизации
   }
   this->window_auth->show(); // показываем окно авторизации
}

