#include "network_connection_state.h"
#include "ui_network_connection_state.h"
#include <thread>
#include <chrono>
#include <fstream>
#include <notification.h>
#include <json_manager.h>

network_connection_state* network_connection_state::instance = nullptr; // инициализируем статическую переменную
static std::atomic<bool> flag_stop_thread = false; // флаг для остановки потока

network_connection_state* network_connection_state::get_instance(Client* client_object) {
   if (!network_connection_state::instance) { // если объекта-синглтона не существует
      network_connection_state::instance = new network_connection_state(client_object); // создаём объект синглтон.
   }
   return network_connection_state::instance; // возвращаем указатетель на единственный объект класса.
}

network_connection_state::network_connection_state(Client* client_object, QWidget *parent) :
   QWidget(parent),
   ui(new Ui::network_connection_state),
   client_object(client_object)
{
   ui->setupUi(this);
   this->setAttribute(Qt::WA_DeleteOnClose); // вызываем деструктор при закрытии окна.
   this->setWindowFlag(Qt::MSWindowsFixedSizeDialogHint); // фиксируем размер окна.
   flag_stop_thread.store(false); // устанавливаем флаг работы другого потока, который отслеживает состояние подключения.
   this->setWindowTitle("Сетевые настройки"); // устанавливаем заголовок окна.
   this->set_actual_info_in_placeholders(this->client_object->ip, this->client_object->port); // заменяем placeholder на актуальную сетевую информацию
   std::thread check_connect_state([&]() -> void {this->check_connection_state(500);}); // создаём поток, который мониторит состояние подключения.
   check_connect_state.detach();
   this->show(); // показываем окно на экране.
}

network_connection_state::~network_connection_state()
{
   flag_stop_thread.store(true);
   delete ui;
   network_connection_state::instance = nullptr;
}

void network_connection_state::set_actual_info_in_placeholders() const // функция которая обновляет placeholder на актуальную информацию
{
   ui->line_edit_ip_address->setPlaceholderText(QString("Ваш текущий IP: %1").arg(json_manager::get_data_from_json(json_manager::json_manager_network::Network).ip));
   ui->line_edit_port->setPlaceholderText(QString("Ваш текущий порт: %1").arg(json_manager::get_data_from_json(json_manager::json_manager_network::Network).port));
}

void network_connection_state::set_actual_info_in_placeholders(const QString &ip, const int &port) const // функция которая обновляет placeholder по переданным аргументам.
{
   ui->line_edit_ip_address->setPlaceholderText(QString("Ваш текущий IP: %1").arg(ip));
   ui->line_edit_port->setPlaceholderText(QString("Ваш текущий порт: %1").arg(QString::number(port)));
}

void network_connection_state::check_connection_state(int interval_ms)
{
   while (flag_stop_thread.load() == false) { // когда std::atomic<bool>flag_stop_thread == false
      if (this->client_object->get_socket_state() == QAbstractSocket::ConnectedState) { // если мы подключены к серверу
         ui->label_state_on->show(); // показываем сообщение о том, что имеется подключение.
         ui->label_state_off->hide(); // прячем сообщение о том, что нет подключения к клиенту.
      }
      else {
         ui->label_state_off->show(); // показываем сообщение о том, что нет подключения.
         ui->label_state_on->hide(); // прячем сообщение о том, что есть подключение.
      }
      //set_actual_info_in_placeholders(); // вставляем в placeholders актуальную информацию
      std::this_thread::sleep_for(std::chrono::milliseconds(interval_ms)); // засыпаем на interval_ms
   }
}

QJsonDocument network_connection_state::read_json(const QString& path) {
   QJsonDocument json_data;
   std::fstream json_file;
   std::string lines_from_file;

   // считываем данные из JSON-файла в переменную QJsonDocument json_data
   json_file.open(path.toStdString().c_str(), std::ios_base::in);
   if (json_file.is_open()) {
      qDebug() << "json file успешно открыт";
      std::string line_from_file;
      while (std::getline(json_file, line_from_file)) {
         lines_from_file += line_from_file;
      }
      json_data= QJsonDocument::fromJson(QByteArray(lines_from_file.c_str()));
      return json_data;
   }
   else {
      qDebug() << "Ошибка при открытии json-файла";
      throw std::runtime_error("Ошибка при открытии JSON-файла.");
   }
}


void network_connection_state::on_pushButton_try_to_connect_clicked()
{
   const QString ip = ui->line_edit_ip_address->text();
   const int port = ui->line_edit_port->text().toInt();
   if (ip.isEmpty() or port == 0)
      notification::create_instance("Ошибка", "Заполните значение полей корректными значениями.");
   else {
      this->client_object->ip = ip;
      this->client_object->port = port;
      this->client_object->connect_to_server(); // подключение к серверу по введенным данным.
      if (ui->checkBox_save_config->isChecked()) {
         json_manager::write_network_to_json(ip, port);
      }
      this->set_actual_info_in_placeholders(ip, port);
   }
}

