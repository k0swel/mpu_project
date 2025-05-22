#include <QCoreApplication>
#include "mytcpserver.h"
#include <QThread>
#include "dbsingleton.h"
#include <QDir>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << "Сервер запущен. Главный поток сервера: " << QThread::currentThreadId();
    MyTcpServer* myserv = MyTcpServer::create_instance(); // Сервер
    DBSingleton* db = DBSingleton::getInstance(); // База данных
    return a.exec();
}
