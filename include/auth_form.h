#ifndef AUTH_FORM_H
#define AUTH_FORM_H

#include <QWidget>
#include "client.h"
#include <QCloseEvent>


class reset_password; // класс окна сброса пароля
class Widget; // класс окна регистрации
class client_main_window; // класс окна клиента

namespace Ui {
class auth_form;
}

class auth_form : public QWidget
{
   Q_OBJECT

public:
   explicit auth_form(Client* client_socket, QWidget *parent = nullptr);
   ~auth_form();

private slots:
   void on_pushButton_login_clicked(); //  нажата кнопка авторизации
   void on_pushButton_reset_password_clicked(); //  нажата кнопка сброса пароля
   void on_pushButton_to_reg_clicked(); //  нажата кнопка региистрации

   // СЛОТЫ АВТОРИЗАЦИИ
   void auth_ok(); // успешная авторизация
   void auth_error(); // ошибка при авторизации

   void on_pushButton_draw_password_pressed(); // функция отображает пароль при зажатой клавиши

   void on_pushButton_draw_password_released(); // функция при отпускании кнопки обратно прячет пароль

   void on_pushButton_settings_clicked(); // вызываем окно с настройками.

private:
   Ui::auth_form *ui;
   Client* client = nullptr;
   void create_notification(QString title, QString text);
};

#endif // AUTH_FORM_H
