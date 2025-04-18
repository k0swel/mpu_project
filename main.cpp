#include <QCoreApplication>
#include "mytcpserver.h"
#include <QThread>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << "Сервер запущен. Главный поток сервера: " << QThread::currentThreadId();
    MyTcpServer* myserv = MyTcpServer::create_instance(); // server
    return a.exec();
}
