#ifndef REG_FORM_H
#define REG_FORM_H

#include <QWidget>
#include <QApplication>
#include <QScreen>
#include "client.h"
#include <QCloseEvent>

class auth_form;
class client_main_window;

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
   Q_OBJECT

public:
   Widget(Client* client, QWidget *parent = nullptr);
   ~Widget();

private slots:
   void on_toolButton_auth_clicked(); // нажата кнопка авторизации

   // СЛОТЫ РЕГИСТРАЦИИ
   void register_successful(); // успешная регистрация
   void register_error(); // ошибка при регистрации


   void on_pushButton_draw_password_pressed(); // если зажата кнопка, то отображаем наш пароль

   void on_pushButton_draw_password_released(); // если отпущена кнопка, то прячем наш пароль

   void on_pushButton_reg_clicked();

   void on_pushButton_settings_clicked();

private:
   Ui::Widget *ui;
   Client* client = nullptr;
   void create_notification(QString title, QString text);
   void reset_text();
};
#endif // REG_FORM_H
