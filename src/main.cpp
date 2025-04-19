#include "reg_form.h"
#include <QApplication>
#include <client.h>
#include "notification.h"
#include "QValidator"
#define window Widget
#pragma GCC poison Widget

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
   Client* make_client = Client::get_instance(); // создаём единственный экземпляр клиента
   window* window_reg = new window(make_client); // создаём окно регистрации
   return a.exec();
}
