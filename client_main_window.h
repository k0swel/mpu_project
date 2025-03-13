#ifndef CLIENT_MAIN_WINDOW_H
#define CLIENT_MAIN_WINDOW_H

#include <QMainWindow>

namespace Ui {
class client_main_window;
}

class client_main_window : public QMainWindow
{
   Q_OBJECT

public:
   explicit client_main_window(QWidget *parent = nullptr);
   ~client_main_window();

private:
   Ui::client_main_window *ui;
};

#endif // CLIENT_MAIN_WINDOW_H
