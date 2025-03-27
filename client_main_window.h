#ifndef CLIENT_MAIN_WINDOW_H
#define CLIENT_MAIN_WINDOW_H

#include <QMainWindow>

class Widget; // класс окна регистрации
class Client; // класс клиента
namespace Ui {
class client_main_window;
}

class client_main_window : public QWidget
{
   Q_OBJECT

public:
   explicit client_main_window(Client* client, Widget* window_reg, QWidget *parent = nullptr); // конструктор, который принимает окно регистрации
   ~client_main_window();

private slots:
   void on_pushButton_clicked(); // кнопка выхода из учётной записи.

   void on_comboBox_activated(int index); // combo box с выбором вида уравнения

   void on_pushButton_solve_equation_clicked(); // кнопка отправки уравнения на сервер.

private:
   Ui::client_main_window *ui;
   Widget* reg_window = nullptr; // окно регистрации.
   Client* client = nullptr; // класс клиента
};

#endif // CLIENT_MAIN_WINDOW_H
