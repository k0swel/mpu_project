#ifndef CLIENT_H
#define CLIENT_H
#include <QTcpSocket>
#include <QByteArray>
#include <QObject>
#include <QString>

class Client: public QObject
{
   Q_OBJECT
public:
   Client();

private:
   QTcpSocket* socket;
   int port = 33333; // порт, куда подключается клиент
   static QString get_client_time();

private slots:
   void connect_to_server();
   void read();
};

#endif // CLIENT_H
