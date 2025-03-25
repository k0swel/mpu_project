#ifndef CLIENT_H
#define CLIENT_H
#include <QTcpSocket>
#include <QByteArray>
#include <QObject>
#include <QString>
class Client;

class SingletonDestroyer {
private:
   static Client* client_connection;
   static QTcpSocket* socket;
public:
   static void initialize(Client* element, QTcpSocket* socket);
   ~SingletonDestroyer();
   SingletonDestroyer();
};

class Client: public QObject
{
   Q_OBJECT
public:
   bool write(QString text); // отправить сообщение серверу.
   static Client* get_instance(); // создаём единственный экземпляр клиента
   ~Client(); // причем деструктор
private:
   static QTcpSocket* socket;
   static Client* p_instance;
   static int port;
   Client(); // прячем конструктор
   static SingletonDestroyer el;
private slots:
   void connect_to_server();
   void disconnect_from_server();
   void read();
};

#endif // CLIENT_H
