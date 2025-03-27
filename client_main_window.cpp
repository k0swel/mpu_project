#include "client_main_window.h"
#include "ui_client_main_window.h"
#include "reg_form.h"
#include "client.h"
#include "clients_func.h"
#include <QMessageBox>


client_main_window::client_main_window(Client* client, Widget* window_reg, QWidget *parent) :
   QWidget(parent),
   ui(new Ui::client_main_window),
   reg_window(window_reg),
   client(client)
{
   ui->setupUi(this);
   this->setWindowFlag(Qt::WindowType::MSWindowsFixedSizeDialogHint); // устанавливаем свойство невозможности смены размера окна.
   this->setWindowTitle(QString("Метод половинного деления")); // устанавливаем заголовок окна
   ui->pushButton->setToolTip("Выйти из учётной записи."); // устанавливаем подсказку при наведении на кнопку выхода из аккаунта.
   ui->comboBox->setToolTip("Выберите вид уравнения."); // устанавливаем подсказку на combo box
   ui->comboBox->setToolTipDuration(10000);
   clients_func::equation(ui->Layout_quadratic, action::HIDE); // по умолчанию прячем квадратное уравнение.
}

client_main_window::~client_main_window()
{
   delete ui;
}

void client_main_window::on_pushButton_clicked() // если нажата кнопка выхода из учётной записи.
{
   this->hide(); // закрываем текущее окно
   this->reg_window->show(); // показываем окно регистрации
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
      QString text_in_dialogbox = QString("Ваше уравнение: %1%2x%3%4 = 0").arg(ui->comboBox_sign_linear->currentText()).arg(ui->lineEdit_a_linear->text()).arg(ui->comboBox_sign2_linear->currentText()).arg(ui->lineEdit_b_linear->text());
      QMessageBox::information(this,QString("Вы подтверждаете своё уравнение?"), text_in_dialogbox + QString("\n\nПодтверждаете отправку?"));
      this->client->write(QString("equation|linear|%1$%2").arg(ui->lineEdit_a_linear->text()).arg(ui->lineEdit_b_linear->text()));
      // отправляем линейное уравнение на сервер.
   }
   if (ui->comboBox->currentIndex() == 1) { // значит пользователь отправил квадратное уравнение
      this->client->write((QString("equation|quadratic|%1$%2$%3").arg(ui->lineEdit_a_quadratic->text()).arg(ui->lineEdit_b_quadratic->text()).arg(ui->lineEdit_c_quadratic->text())));
      // отправляем квадратное уравнение.
   }
}

