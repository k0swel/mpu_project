#ifndef NETWORK_CONNECTION_STATE_H
#define NETWORK_CONNECTION_STATE_H

#include <QWidget>
#include "client.h"
#include "json_manager.h"


namespace Ui {
class network_connection_state;
}

class network_connection_state : public QWidget
{
   Q_OBJECT

public:
   network_connection_state(const network_connection_state&) = delete; // удаляем конструктор копирования для синглтона.
   static network_connection_state* get_instance(Client* client_object); // конструктор для синглтона
   network_connection_state& operator=(network_connection_state&) = delete; // удаляем оператор присваивания для синглтона.
   static QJsonDocument read_json(const QString& path = "./cache/cache.json");

   ~network_connection_state();

private slots:
   void on_pushButton_try_to_connect_clicked();

private:
   Ui::network_connection_state *ui;
   explicit network_connection_state(Client* client_object, QWidget *parent = nullptr); // делаем конструктор приватным, чтобы реализовать синглтон.
   Client* client_object = nullptr; // указатель на синглтон клиента.
   static network_connection_state* instance; // статическая переменная, указывающая на класс синглтон.
   void set_actual_info_in_placeholders() const; // функция которая обновляет placeholder на актуальную информацию из JSON-файла
   void set_actual_info_in_placeholders(const QString& ip, const int& port) const; // вставляем информацию в placeholders из input
   void check_connection_state(int interval_ms); // функция, которая в другом потоке будет следить за состоянием сокета
};
#endif // NETWORK_CONNECTION_STATE_H
