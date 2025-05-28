#include <QCoreApplication>
#include "mytcpserver.h"
#include <QThread>
#include <cstdio>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MyTcpServer* myserv = MyTcpServer::create_instance(); // Сервер
    return a.exec();
}
