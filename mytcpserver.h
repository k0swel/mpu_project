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


class MyTcpServer;

class MyTcpServerDestroyer {
public:
   void initialize(MyTcpServer* server, functions_for_server* functions);
   ~MyTcpServerDestroyer();
private:
   MyTcpServer* server;
   functions_for_server* functions;
};

class MyTcpServer : public QObject
{
    Q_OBJECT
public:
   static MyTcpServer* create_instance();
    ~MyTcpServer();
   static MyTcpServerDestroyer* destroyer;
   static MyTcpServer* p_instance;

private slots:
    void slotNewConnection();     
private:
    explicit MyTcpServer(QObject *parent = nullptr);
   MyTcpServer(const MyTcpServer&) = delete;
    QTcpServer * mTcpServer;
    QTcpSocket* temp;
    //int server_status;
};
#endif // MYTCPSERVER_H
