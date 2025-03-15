#ifndef CLIENT_OBJECT_H
#define CLIENT_OBJECT_H

#include <QObject>
#include <QTcpSocket>
#include <QThread>

class client: public QObject
{
   Q_OBJECT
public:
   client(qintptr client_description);
   ~client();

public slots:
   void initialization();

private slots:
   void slot_close_connection();
   void slot_read_from_client();

signals:
   void finished();
private:
   QTcpSocket* client_socket = nullptr;
   qintptr client_description;
   QThread* thread_for_client = nullptr;
   static void hello_message();
   static void bye_message();
};

#endif // CLIENT_OBJECT_H
