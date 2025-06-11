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
#include <QClipboard>
#include "network_connection_state.h"

static void set_icon_to_button_settings(QPushButton* pushButton_settings) {
   pushButton_settings->setIcon(QIcon(":/settings/C:/Users/k0swel/Downloads/settings icon.svg"));
   pushButton_settings->setIconSize(QSize(40, 40));
   pushButton_settings->setStyleSheet(
       "QPushButton#pushButton_settings {"
       "   background: transparent;"  // Прозрачный фон в обычном состоянии
       "   border: none;"            // Убираем границу
       "}"
       "QPushButton#pushButton_settings:hover {"
       "   background: rgba(0,0,0,0.5);" // Прозрачный фон при наведении
            "border-radius: 10px;"
       "   padding: 5px;"
       "}"
       "QPushButton#pushButton_settings:pressed {"
       "   background: transparent;" // Прозрачный фон при нажатии
       "}"
   );

}

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

   connect(this->client, &Client::reset_error, this, &reset_password::slot_reset_error); // если ошибка при сбросе пароля (не найден аккаунт)
   connect(this->client, &Client::signal_successfully_send_code_to_email, this, &reset_password::slot_reset_send_code_to_email); // если код отправлен на email клиента
   connect(this->client, &Client::signal_fail_send_code_to_email, this, &reset_password::slot_fail_send_code_to_email_client); // если код не был отправлен на email клиента из-за ошибок на стороне сервера.
   ui->lineEdit_code->setValidator(new QIntValidator(0, 2147483647, this)); // устанавливаем допустимый диапозон кода
   this->setWindowFlag(Qt::MSWindowsFixedSizeDialogHint); // запрещаем изменять размер окна
   this->setWindowTitle(QString("Метод половинного деления"));
   this->setAttribute(Qt::WA_DeleteOnClose); // удаляем окно при нажатии на значок закрытия.
   set_icon_to_button_settings(ui->pushButton_settings);
   ui->pushButton_update->setIcon(QIcon(QPixmap(":/update_icon/C:/Users/k0swel/Downloads/update_icon.png")));
   ui->pushButton_update->setIconSize(QSize(50,50));
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
      }
   }
   else {
      notification::create_instance("Ошибка", "Заполните поле ""Логин"". Оно не должно быть пустым!");
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
      auto dialog_result = clients_func::create_messagebox("Обновление пароля",
               QString("Ваш новый пароль: %1.\n\n Сохранить пароль в буфере обмена?").arg(new_password).arg(hash_new_password),
                  clients_func::dialog_style::WITH_BTN); // диалог с кнопками
      if (dialog_result == clients_func::dialog_return_button::BTN_YES) {
         QApplication::clipboard()->setText(new_password, QClipboard::Clipboard); // сохраняем пароль в буфере обмена
      }
      this->hide(); // прячем текущее окно
      new auth_form(this->client); // создаём окно авторизации.
      this->close(); // закрываем текущее окно
   }
   else {
      clients_func::create_messagebox(QString("Ошибка"), QString("Вы ввели некорректный код. Попробуйте ещё раз"),
                                      clients_func::dialog_style::NO_BTN);
   }
}

void reset_password::slot_reset_error()
{
   ui->pushButton_reset_password->show(); // делаем активным кнопку сброса пароля.
   ui->pushButton_code->hide(); // прячем кнопку отправки кода.
   ui->lineEdit_code->hide(); // прячем lineedit ввода кода.
   ui->label_code->hide(); // прячемт текст, относящийся к коду.
   ui->lineEdit_login->setEnabled(true); // делаем активной кнопку ввода логина.
   notification::create_instance("Ошибка", "Пользователя с указанным логином не существует. Попробуйте зарегистрироваться."); // уведомление о том, что пользователя с указанным логином не существует
}

void reset_password::slot_reset_send_code_to_email() { // если код отправлен на email клиента
   ui->pushButton_reset_password->hide();
   ui->pushButton_code->show();
   ui->lineEdit_code->show();
   ui->label_code->show();
   notification::create_instance("Уведомление", "На ваш почтовый ящик, соответствующий вашему логину, был отправлен код подтверждения!");
}

void reset_password::slot_fail_send_code_to_email_client() {
   notification::create_instance("Ошибка", "На стороне сервера неполадки при попытке отправить письмо вам на почту. Попробуйте позже");
}


void reset_password::on_pushButton_clicked() // кнопка обновления окна
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


void reset_password::on_pushButton_settings_clicked()
{
   network_connection_state::get_instance(this->client); // создаём окно с сетевыми настройками
}

