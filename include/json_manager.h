#ifndef JSON_MANAGER_H
#define JSON_MANAGER_H
#include <QJsonDocument>
#include <QJsonObject>
#include <filesystem>
#include <fstream>
#include <QJsonValue>
#include <string>
#include <cstring>

class json_manager {
public:
   static void create_json_file(const QString& path, const QString& filename); // функция для первоначального создания JSON-файла
   static void write_data_in_json(QJsonDocument& doc, const QString& path = json_manager::path_to_file); // функция для записи JSON-документа в файл.
   static QJsonDocument read_json_file(); // функция для чтения JSON-файла. Возвращает QJsonDocument

   struct login_and_password { // структура для хранения логина и пароля.
      QString login;
      QString password;
   };
   struct ip_and_port { // структура для хранения IP и порта.
      QString ip;
      int port;
   };

   enum class json_manager_auth {
      Authentication,
   };

   enum class json_manager_network {
      Network,
   };

   static typename json_manager::login_and_password get_data_from_json(json_manager_auth); // возвращает структуру login и пароль.
   static typename json_manager::ip_and_port get_data_from_json(json_manager_network); // возвращает структуру ip и порт.
   static void write_authentication_to_json(QString login, QString password); // записываем в объект JSON логин и пароль.
   static void write_network_to_json(QString ip, int port);
private:
   static QString path_to_file;
   json_manager() = delete;
   json_manager(const json_manager&) = delete;
   json_manager& operator=(const json_manager&) =delete;
};
#endif
