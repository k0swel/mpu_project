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
   // QString& get_ip() const; // геттер и сеттер IP-адреса сервера.
   // int& get_port() const; // геттер и сеттер порта-сервера
   QAbstractSocket::SocketState get_socket_state() const; // получаем состояние сокета. Getter.
   QString ip; // IP-адрес, куда будет подключаться клиент.
   int port; // порт, куда будет подключаться клиент.
   void connect_to_server(); // подключаемся к серверу.
   ~Client();
private:
   static QTcpSocket* socket;
   static Client* p_instance;
   Client(); // прячем конструктор
   static SingletonDestroyer el;

   QByteArray buffer; // буфер хранения пришедших сообщений.
private slots:
   void disconnect_from_server();
   void read();

signals:
   // СИГНАЛЫ РЕГИСТРАЦИИ
   void register_ok(); // корректная регистрация
   void register_error(); // такой пользователь уже зарегистрирован.

   // СИГНАЛЫ АВТОРИЗАЦИИ
   void auth_ok(); // успешная авторизация.
   void auth_error(); // ошибка при авторизации.

   // СИГНАЛЫ ДЛЯ ОКНА СБРОСА ПАРОЛЯ
   void reset_error(); // пользователь отсутствует в БД сервера
   void signal_fail_send_code_to_email(); // ошибка при отправке кода на почту клиента
   void signal_successfully_send_code_to_email(); // код на почту клиента отправлен успешно

   // СИГНАЛЫ ДЛЯ ГЛАВНОГО ОКНА
   void equation_ok(QString&); // корректное решение уравнения.
   void equation_fail(QString&); // отсутствует решение уравнения.
};

#endif // CLIENT_H
