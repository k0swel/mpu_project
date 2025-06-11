#include "json_manager.h"

#define DEFAULT_IP "127.0.0.1"
#define DEFAULT_PORT 8080

static QJsonObject main_object = QJsonObject();
QString json_manager::path_to_file = "./cache/cache.json";

void json_manager::create_json_file(const QString& path, const QString& filename)
{
   if (!std::filesystem::exists(std::filesystem::path("./cache/cache.json"))) {
      std::filesystem::create_directory(path.toStdString());
      QJsonDocument json_doc; // главный документ JSON-файла
      main_object.insert("authentication", QJsonObject({{"login", QString("unknown")}, {"password", QString("unknown")}})); // раздел authentication
      main_object.insert("network", QJsonObject({{"ip", DEFAULT_IP}, {"port", DEFAULT_PORT}})); // раздел network
      json_doc.setObject(main_object);
      QString path_filename = QString("%1/%2").arg(path).arg(filename); // путь к текстовому файлу.
      write_data_in_json(json_doc, path_filename); // записываем JSON-объект в текстовый файл.
   }

}

void json_manager::write_data_in_json(QJsonDocument &doc, const QString& path)
{
   std::fstream file;
   file.open(path.toStdString().c_str(), std::ios_base::out);
   if (file.is_open()) {
      json_manager::path_to_file = path; // в статическую переменную сохраняем путь к JSON-файлу
      std::string json_data_in_c = doc.toJson().toStdString(); // JSON-объект преобразуем в const char* для записи в файловый поток.
      file.write(json_data_in_c.c_str(), json_data_in_c.size()); // записываем JSON-объект.
      file.close(); // закрываем объект.
   }
   else {
      throw std::runtime_error(QString("Ошибка при открытии JSON-файла по директории %path.").toStdString().c_str());
   }
}

QJsonDocument json_manager::read_json_file()
{
   std::fstream file;
   file.open(json_manager::path_to_file.toStdString().c_str(), std::ios_base::in);

   if (file.is_open()) {
      std::string lines_from_file;
      std::string temp;
      while (std::getline(file, temp)) {
         lines_from_file += temp;
      }
      QJsonDocument doc = QJsonDocument::fromJson(QByteArray(lines_from_file.data(), lines_from_file.size()));
      file.close();
      return doc;
   }
   else {
      throw std::runtime_error(QString("Ошибка при открытии JSON-файла по директории %1.").arg(path_to_file).toStdString().c_str());
   }
}

typename json_manager::ip_and_port json_manager::get_data_from_json(json_manager_network)
{
   QJsonDocument doc = read_json_file();
   std::fstream file;
   file.open(json_manager::path_to_file.toStdString().c_str(), std::ios_base::in);

   if (file.is_open()) {
      json_manager::ip_and_port ip_and_port;
      ip_and_port.ip = doc.object()["network"].toObject()["ip"].toString();
      ip_and_port.port = doc.object()["network"].toObject()["port"].toInt();
      file.close();
      return ip_and_port;
   }
   else {
      std::runtime_error(QString("Ошибка при открытии JSON-файла по директории %path.").toStdString().c_str());
   }
}

void json_manager::write_authentication_to_json(QString login, QString password)
{
   QJsonDocument doc = read_json_file();
   std::fstream file;
   file.open(json_manager::path_to_file.toStdString().c_str(), std::ios_base::out);
   if (file.is_open()) {
      QJsonObject root = doc.object();
      QJsonObject authentication = root["authentication"].toObject();
      authentication.insert("login", login);
      authentication.insert("password", password);
      root["authentication"] = authentication;
      doc.setObject(root);
      write_data_in_json(doc, json_manager::path_to_file); // записываем JSON-документ в текстовый файл.
      return;
   }
   else {
      throw std::runtime_error("Произошла ошибка при открытии JSON-файла.");
   }
}

void json_manager::write_network_to_json(QString ip, int port)
{
   QJsonDocument doc = read_json_file();
   std::fstream file;
   file.open(json_manager::path_to_file.toStdString().c_str(), std::ios_base::out);
   if (file.is_open()) {
      QJsonObject root = doc.object();
      QJsonObject authentication = root["network"].toObject();
      authentication.insert("ip", ip);
      authentication.insert("port", port);
      root["network"] = authentication;
      doc.setObject(root);
      write_data_in_json(doc, json_manager::path_to_file); // записываем JSON-документ в текстовый файл.
      return;
   }
   else {
      throw std::runtime_error("Произошла ошибка при открытии JSON-файла.");
   }
}

typename json_manager::login_and_password json_manager::get_data_from_json(json_manager_auth)
{
   QJsonDocument doc = read_json_file();
   std::fstream file;
   file.open(json_manager::path_to_file.toStdString().c_str(), std::ios_base::in);
   if (file.is_open()) {
      json_manager::login_and_password login_and_password;
      login_and_password.login = doc.object()["authentication"].toObject()["login"].toString();
      login_and_password.password = doc.object()["authentication"].toObject()["password"].toString();
      return login_and_password;
   }
   else {
      std::runtime_error(QString("Ошибка при открытии JSON-файла по директории %path.").toStdString().c_str());
   }
}
