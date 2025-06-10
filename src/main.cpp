#include "reg_form.h"
#include <QApplication>
#include <client.h>
#include "notification.h"
#include "reg_form.h"
#include "json_manager.h"

#define window Widget

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
   a.setWindowIcon(QIcon(":/icons/icons/main_icon.ico")); // иконка приложения
   Client* make_client = Client::get_instance(); // создаём единственный экземпляр клиента
   window* window_reg = new window(make_client); // создаём окно регистрации
   return a.exec();
}
