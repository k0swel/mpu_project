#ifndef CLIENT_OBJECT_H
#define CLIENT_OBJECT_H

#include <QObject>
#include <QTcpSocket>
#include <QThread>

class client: public QObject
{
   Q_OBJECT
public:
   client(qintptr client_description, QObject* parent = nullptr);
   ~client();

public slots:
   void initialization(); // инициализируем каждого клиента
private slots:
   void slot_close_connection(); // слот закрытия соединения
   void slot_read_from_client(); // слот получения нового сообщения от клиента

   // РЕГИСТРАЦИЯ
   void slot_register_ok(); // отправка клиенту сообщение об успешной регистрации.
   void slot_register_error(); // отправку клиенту сообщение об ошибке при регистрации.

   // АВТОРИЗАЦИЯ
   void slot_auth_ok(); // отправка клиенту сообщение об успешной авторизации.
   void slot_auth_error(); // отправка клиенту сообщение об ошибке при авторизации.

   // СБРОС ПАРОЛЯ
   void slot_reset_error(); // сигнал об ошибке при сбросе пароля (не найден логин в БД).
   void slot_reset_ok();    // Сигнал о том, что пароль сброшен успешно


   // ГЛАВНОЕ КЛИЕНТСКОЕ ОКНО
   void slot_equation_solution(QString answer); // отправляем сообщение о решении любого уравнения клиенту

signals:
   void finished(); // для закрытия потока клиента

   // СИГНАЛ ДЛЯ РЕГИСТРАЦИИ
   void signal_register_new_account(QString login, QString password, QString email, QString last_name, QString first_name, QString middle_name, client* client); // слот для регистрации аккаунта

   // СИГНАЛ ДЛЯ АВТОРИЗАЦИИ
   void signal_auth(QString login, QString password, client* client);

   // СБРОС ПАРОЛЯ
   void signal_send_code_to_email(QString email, QString code); // сигнал отправки кода на почту клиента
   void signal_set_new_password(QString email, QString password); // сигнал установки нового пароля на аккаунт клиента.


   // ГЛАВНОЕ КЛИЕНТСКОЕ ОКНО
   void signal_linear_equation(QString a, QString b, client* client); // сигнал на решение клиентского уравнения
   void signal_quadratic_equation(QString a, QString b, QString c, client* client) ; // сигнал на решение квадратного уравнения

   void del_thread(); // сигнал удаления потока.

private:
   QTcpSocket* client_socket;
   qintptr client_description;
   QThread* thread_for_client = nullptr;
   static void hello_message(); // функция отправки сообщения в консоль при каждом новом подключении
   static void bye_message(); // функция отправки сообщения в консоль при каждом отключении
   void send_message(QString message); // отправляем сообщение клиенту.
};

#endif // CLIENT_OBJECT_H
