#include <QCoreApplication>
#include "mytcpserver.h"
#include "functions_for_server.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MyTcpServer myserv; // server
    return a.exec();
}
