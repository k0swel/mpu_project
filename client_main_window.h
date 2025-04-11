#ifndef CLIENT_MAIN_WINDOW_H
#define CLIENT_MAIN_WINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QIntValidator>

class Widget; // класс окна регистрации
class Client; // класс клиента
namespace Ui {
class client_main_window;
}

class client_main_window : public QWidget
{
   Q_OBJECT

public:
   explicit client_main_window(Client* client, QWidget *parent = nullptr); // конструктор, который принимает окно регистрации
   ~client_main_window();

private slots:
   void on_pushButton_clicked(); // кнопка выхода из учётной записи.

   void on_comboBox_activated(int index); // combo box с выбором вида уравнения

   void on_pushButton_solve_equation_clicked(); // кнопка отправки уравнения на сервер.

   void slot_equation_ok(QString answer); // слот при успешном решении уравнения.
   void slot_equation_fail(); // слот при ошибке при решении линейного уравнения.

private:
   Ui::client_main_window *ui;
   Client* client = nullptr; // класс клиента
   void line_edit_set_validator(); // устанавливаем минимальные и максимальные значения в lineedit
};

#endif // CLIENT_MAIN_WINDOW_H
