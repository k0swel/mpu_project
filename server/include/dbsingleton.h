#ifndef DBSINGLETON_H
#define DBSINGLETON_H


#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QObject>
#include <QDebug>
#include <QVariantList>
#include "functions_for_server.h"

class DBSingletonDestroyer; // Предварительное объявление

class DBSingleton : public QObject {
    Q_OBJECT

private:
    static DBSingleton* instance;
    static DBSingletonDestroyer destroyer;
    QSqlDatabase db;

    // Приватный конструктор
    DBSingleton();

    DBSingleton(const DBSingleton&) = delete; // Запрет копирования
    DBSingleton& operator=(const DBSingleton&) = delete; // Запрет присваивания

    functions_for_server* servers_functions;

    friend class DBSingletonDestroyer;

public:
    static DBSingleton* getInstance(); // Метод для получения экземпляра
    QSqlDatabase getDatabase(); // Метод для получения базы данных
    ~DBSingleton();// Деструктор

    bool executeQuery(const QString& queryStr); // Выполнение произвольного запроса
    QVariantList fetchData(const QString& queryStr); // Получение данных

signals:
    // РЕГИСТРАЦИЯ
    void register_ok(); // сигнал об успешной регистрации
    void register_error(); // сигнал об ошибке при регистрации.

    // АВТОРИЗАЦИЯ
    void auth_ok(); // сигнал об успешной авторизации.
    void auth_error(); // сигнал об ошибке при авторизации.

    // ОКНО СБРОСА ПАРОЛЯ
    void reset_error(); // сигнал о том, что логин пользователя в БД не найден и соответственно некуда отправить код подтверждения.
    void reset_ok();    // Сигнал о том, что пароль сброшен успешно

public slots:
    // РЕГИСТРАЦИЯ
    void slot_register_new_account(QString login, QString password, QString email, QString last_name, QString first_name, QString middle_name, client* client); // слот для регистрации аккаунта

    // АВТОРИЗАЦИЯ
    void slot_auth(QString login, QString password, client* client);

    // СБРОС ПАРОЛЯ
    void slot_send_code(QString login, QString code); // функция отправки кода на почту клиента.
    void slot_new_password(QString login, QString password); // функция для установки нового пароля клиенту.


};

class DBSingletonDestroyer {
private:
    DBSingleton* instance;

public:
    ~DBSingletonDestroyer(); // Деструктор
    void initialize(DBSingleton* link); // Метод инициализации
};

#endif // DBSINGLETON_H
