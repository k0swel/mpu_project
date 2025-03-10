#include "MainWindow.h"
#include "auth_form.h"
#include <QApplication>
#include <client.h>
#include "reset_password.h"
int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
   //Widget w; // регистрация
   // auth_form authorization; // авторизация
   reset_password window_reset_password; // окно восстановления пароля

   return a.exec();
}
