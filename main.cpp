#include "MainWindow.h"
#include "auth_form.h"
#include <QApplication>
#include <client.h>
#include "reset_password.h"
#include "clients_func.h"
int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
   //Widget w; // регистрация
   Client* make_client = new Client;
   Widget window_registration(make_client);


   // reset_password window_reset_password; // окно восстановления пароля

   return a.exec();
}
