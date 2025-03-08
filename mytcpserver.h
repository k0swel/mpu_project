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
class MyTcpServer : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpServer(QObject *parent = nullptr);
   functions_for_server* servers_functions; // функции сервера.
    ~MyTcpServer();

private slots:
    void slotNewConnection();
    void slotClientDisconnected();
    void slotServerRead();
private:
    QTcpServer * mTcpServer;
    QList<QTcpSocket*> sockets;
    QTcpSocket* temp;
    //int server_status;
};
#endif // MYTCPSERVER_H
