#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H
#include <QTcpServer>
#include <QTcpSocket>
#include <QObject>
#include <QtNetwork>
#include <QByteArray>
#include <QDebug>
#include <QList>
#include "functions_for_server.h"
//#include "dbsingleton.h"

class MyTcpServer;

class MyTcpServerDestroyer {
public:
   static MyTcpServerDestroyer destroyer;
   void initialize(MyTcpServer* server, functions_for_server* functions);
   ~MyTcpServerDestroyer();
private:
   MyTcpServer* server; // объект сервера
   functions_for_server* functions; // главные функции сервера
};

class MyTcpServer : public QObject
{
    Q_OBJECT
public:
   static MyTcpServer* create_instance(); // статический метод создания объекта сервера
    ~MyTcpServer();

private slots:
    void slotNewConnection(); // слот нового подключения к серверу
private:
    static MyTcpServer* p_instance; // сервер синглтон
    explicit MyTcpServer(QObject *parent = nullptr); // конструктор
    MyTcpServer(const MyTcpServer&) = delete;
    QTcpServer * mTcpServer;
    QTcpSocket* temp;
    int get_port(QString environment_variable); // Порт из переменной окружения
    //DBSingleton *db;
    //int server_status;
};
#endif // MYTCPSERVER_H
