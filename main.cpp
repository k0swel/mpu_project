#include "MainWindow.h"

#include <QApplication>
#include <client.h>

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
   Widget w;
   return a.exec();
}
