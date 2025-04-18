#include "client_main_window.h"
#include "ui_client_main_window.h"
#include "reg_form.h"
#include "client.h"
#include "clients_func.h"
#include <QMessageBox>
#include <QLabel>
#include "notification.h"

#define NOTIFICATION_ERROR "Убедитесь, что вы ввели корректные коэффициенты."

client_main_window::client_main_window(Client* client, QWidget *parent) :
   QWidget(parent),
   ui(new Ui::client_main_window),
   client(client)
{
   ui->setupUi(this);
   this->setWindowFlag(Qt::WindowType::MSWindowsFixedSizeDialogHint); // устанавливаем свойство невозможности смены размера окна.
   this->setWindowTitle(QString("Метод половинного деления")); // устанавливаем заголовок окна
   ui->pushButton->setToolTip("Выйти из учётной записи."); // устанавливаем подсказку при наведении на кнопку выхода из аккаунта.
   ui->comboBox->setToolTip("Выберите вид уравнения."); // устанавливаем подсказку на combo box
   this->setAttribute(Qt::WA_DeleteOnClose); // удаляем окно при нажатии на значок закрытия.
   clients_func::equation(ui->Layout_quadratic, action::HIDE); // по умолчанию прячем квадратное уравнение.
   QWidget* widget_for_equations = new QWidget(this); // создаём виджет куда поместил layout с элементами уравнения
   this->line_edit_set_validator(); // устанавливаем мин и макс.значения для line editов

   connect(this->client, &Client::equation_ok, this, &client_main_window::slot_equation_ok); // connect об успешном решении уравнения
   connect(this->client, &Client::equation_fail, this, &client_main_window::slot_equation_fail); // connect об отсутствии корней в уравнении

   this->show(); // показыаем текущее окно
}

client_main_window::~client_main_window()
{
   qDebug() << "Вызвался деструктор окна клиента";
   delete ui;
}

void client_main_window::on_pushButton_clicked() // если нажата кнопка выхода из учётной записи.
{
   this->hide(); // прячем текущее окно
   new Widget(this->client); // создаём окно регистрации
   this->close(); // закрываем текущее окно.
}


void client_main_window::on_comboBox_activated(int index)
{
   if (index == 0) {
      clients_func::equation(ui->Layout_quadratic, action::HIDE); // прячем квадратное уравнение
      clients_func::equation(ui->layout_linear, action::SHOW); // показываем линейное уравнение
   }
   else if (index == 1) {
      clients_func::equation(ui->Layout_quadratic, action::SHOW); // показываем квадратное уравнение
      clients_func::equation(ui->layout_linear, action::HIDE); // прячем линейное уравнение
   }
}


void client_main_window::on_pushButton_solve_equation_clicked() // метод отправляет на сервер наше уравнение
{
   if (ui->comboBox->currentIndex() == 0) { // значит пользователь отправляет линейное уравнение
      bool bool_arg_a = false;
      int arg_a = ui->lineEdit_a_linear->text().toInt(&bool_arg_a);

      bool bool_arg_b = false;
      int arg_b = ui->lineEdit_b_linear->text().toInt(&bool_arg_b);
      if (arg_a and arg_b) {
         QString text_in_dialogbox = QString("Ваше уравнение: %1%2x%3%4 = 0").arg(ui->comboBox_sign_linear->currentText()).arg(ui->lineEdit_a_linear->text()).arg(ui->comboBox_sign2_linear->currentText()).arg(ui->lineEdit_b_linear->text());
         qDebug() << text_in_dialogbox;
         this->client->write(QString("equation|linear|%1%2$%3%4").arg(ui->comboBox_sign_linear->currentText()).arg(ui->lineEdit_a_linear->text()).arg(ui->comboBox_sign2_linear->currentText()).arg(ui->lineEdit_b_linear->text()));
            // отправляем линейное уравнение на сервер.
      }
      else
         new notification("Ошибка", NOTIFICATION_ERROR, this);
   }

   if (ui->comboBox->currentIndex() == 1) { // значит пользователь отправил квадратное уравнение
      bool bool_arg_a = false;
      int arg_a = ui->lineEdit_a_quadratic->text().toInt(&bool_arg_a);
      bool bool_arg_b = false;
      int arg_b = ui->lineEdit_b_quadratic->text().toInt(&bool_arg_b);

      bool bool_arg_c = false;
      int arg_c = ui->lineEdit_c_quadratic->text().toInt(&bool_arg_c);

      if (arg_a and arg_b and arg_c) {
         this->client->write((QString("equation|quadratic|%1%2$%3%4$%5%6").arg(ui->comboBox_sign2_quardratic->currentText())).arg(ui->lineEdit_a_quadratic->text()).arg(ui->comboBox_sign2_quadratic_2->currentText()).arg(ui->lineEdit_b_quadratic->text()).arg(ui->comboBox_sign2_quadratic_3->currentText()).arg(ui->lineEdit_c_quadratic->text()));
         // отправляем квадратное уравнение на сервер.
      }
      else {
         qDebug() << bool_arg_a << " " << bool_arg_b << " " << bool_arg_c;
         new notification("Ошибка", NOTIFICATION_ERROR);
      }
   }
}

void client_main_window::slot_equation_ok(QString answer) // Слот об успешном решении линейного уравнения
{
   QStringList answers = answer.split("$"); // вытаскиваем из ответа сервера решения уравнения
   QString text_for_notification = QString("Ответ: "); // текст для уведомления
   for (int i = 0; i < answers.size(); i++) {
      text_for_notification += QString("%1 ").arg(answers[i]);
   }
   new notification("Ответ", text_for_notification); // создаём уведомление
}

void client_main_window::slot_equation_fail()
{
   QString text_for_notification = QString("Ошибка. Корней нет!"); // текст для уведомления
   new notification("Ответ", text_for_notification); // создаём уведомление.
}

void client_main_window::line_edit_set_validator() {
   ui->lineEdit_a_linear->setValidator(new QIntValidator(1, 100000,this)); // устанавливаем мин и макс.значения
   ui->lineEdit_b_linear->setValidator(new QIntValidator(1, 100000, this)); // устанавливаем мин и макс.значения
   ui->lineEdit_a_quadratic->setValidator(new QIntValidator(1, 100000, this)); // устанавливаем мин и макс. значения
   ui->lineEdit_b_quadratic->setValidator(new QIntValidator(1, 100000, this)); // устанавливаем мин и макс.значения
   ui->lineEdit_c_quadratic->setValidator(new QIntValidator(1, 100000,this)); // устанавливаем мин и макс.значения
}


