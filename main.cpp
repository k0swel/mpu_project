#include "reg_form.h"
#include <QApplication>
#include <client.h>
#include "notification.h"
#include "QValidator"

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
   Client* make_client = Client::get_instance(); // создаём единственный экземпляр клиента
   Widget* window_reg = new Widget(make_client); // создаём окно регистрации
   return a.exec();
}
