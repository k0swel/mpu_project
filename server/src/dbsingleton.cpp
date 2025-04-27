#include "../include/dbsingleton.h"
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>

// Инициализация статических членов
DBSingleton* DBSingleton::instance = nullptr;
DBSingletonDestroyer DBSingleton::destroyer = DBSingletonDestroyer();

// Конструктор
DBSingleton::DBSingleton() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");
    db.setDatabaseName("./tmp.db");
    //db.setUserName("admin");
    //db.setPassword("123");
    this->servers_functions = functions_for_server::get_instance(); // инициализируем объект функционала сервера.
    if (!db.open()) {
        qDebug() << "Error: Unable to connect to database.";
    } else {
        qDebug() << "Database connected successfully.";
        qDebug() << "Tables: " << db.tables();
        QStringList drivers = QSqlDatabase::drivers();
    }
}
bool DBSingleton::executeQuery(const QString& queryStr) {
    if (!db.open()) {
        qDebug() << "Database is not open.";
        return false;
    }
    QSqlQuery query;
    if (!query.exec(queryStr)) {
        qDebug() << "Query execution error:" << query.lastError().text();
        return false;
    }
    return true;
}


// РЕГИСТРАЦИЯ
void DBSingleton::slot_register_new_account(QString login, QString password, QString email, QString last_name, QString first_name, QString middle_name)
{
    QSqlQuery query;
    if (query.exec("CREATE TABLE students ( id INTEGER PRIMARY KEY AUTOINCREMENT, login TEXT, hash TEXT, email TEXT, name TEXT, surname TEXT, middle_name TEXT )")) {
        qDebug().noquote() << "Запрос на создание таблицы выполнен успешно!";
    }
    else {
        qDebug().noquote() << "Ошибка при выполнении запроса.";
        qDebug().noquote() << QString("Запрос: %1 | Ошибка: %2").arg(query.lastQuery()).arg(query.lastError().text());
    }

    // Проверка на существование пользователя
    QString checkQuery = QString("SELECT COUNT(*) FROM students WHERE login = '%1' OR email = '%2'").arg(login).arg(email);
    QVariantList result = DBSingleton::getInstance()->fetchData(checkQuery);
    if (!result.isEmpty() && result.first().toInt() > 0) {
        emit this->register_error(); // Пользователь уже существует
        return;
    }

    QString insertQuery = QString("INSERT INTO students (login, hash, email, name, surname, middle_name) VALUES (:login, :password, :email, :name, :surname, :middle_name)");
    query.prepare(insertQuery);
    query.bindValue(":login", QVariant(login));
    query.bindValue(":password", QVariant(password));
    query.bindValue(":email", QVariant(email));
    query.bindValue(":name", QVariant(first_name));
    query.bindValue(":surname", QVariant(last_name));
    query.bindValue(":middle_name", QVariant(middle_name));
    if (query.exec()) {
        qDebug() << "Вставка записи успешно!";
        emit this->register_ok(); // Успешная регистрация
    }
    else {
        qDebug() << "Ошибка при вставке записи!";
        qDebug() << query.lastError().text();
        emit this->register_error(); // Ошибка при регистрации
    }
}

// АВТОРИЗАЦИЯ
void DBSingleton::slot_auth(QString login, QString password) {
    QSqlQuery query;
    QString selectQuery = QString("SELECT COUNT(*) FROM students WHERE login = '%1' AND hash = '%2'").arg(login).arg(password);
    QVariantList result = DBSingleton::getInstance()->fetchData(selectQuery);
    if (!result.isEmpty() && result.first().toInt() > 0) {
        emit this->auth_ok(); // Успешная авторизация
    } else {
        emit this->auth_error(); // Ошибка при авторизации
    }
}

// СБРОС ПАРОЛЯ
void DBSingleton::slot_send_code(QString login, QString code) {
    // Проверка на существование пользователя
    QString checkQuery = QString("SELECT email FROM students WHERE login = '%1'").arg(login);
    QVariantList result = DBSingleton::getInstance()->fetchData(checkQuery);
    if (!result.isEmpty()) {
        // Реализация функции отправки кода на почту
       QString email = result[0].toString(); // email-адрес
       this->servers_functions->send_email_to_client(email, code);
    } else {
        emit this->reset_error(); // Логин не найден
    }
}

void DBSingleton::slot_new_password(QString login, QString password) {
    // Проверка на существование пользователя
    QString checkQuery = QString("SELECT COUNT(*) FROM students WHERE login = '%1'").arg(login);
    QVariantList result = DBSingleton::getInstance()->fetchData(checkQuery);

    if (!result.isEmpty() && result.first().toInt() > 0) {
        // Пользователь существует, обновляем пароль
        QString updateQuery = QString("UPDATE students SET hash = '%1' WHERE login = '%2'")
                                  .arg(password).arg(login);

        if (DBSingleton::getInstance()->executeQuery(updateQuery)) {
            emit this->reset_ok(); // Успешный сброс пароля
        } else {
            emit this->reset_error(); // Ошибка при сбросе пароля
        }
    } else {
        emit this->reset_error(); // Логин не найден
    }
}

QVariantList DBSingleton::fetchData(const QString& queryStr) {
    if (!db.isOpen()) {
        qDebug() << "Database is not open.";
        return QVariantList(); // Возвращаем пустой список
    }

    QVariantList results;
    QSqlQuery query;
    if (query.exec(queryStr)) {
        while (query.next()) {
            QVariantList row; // Создаем список для одной строки
            for (int i = 0; i <= 6; ++i) { // Предполагаем, что у нас 6 столбцов
                row.append(query.value(i)); // Добавляем значение каждого столбца в строку
            }
            results.append(row); // Добавляем строку в общий результат
        }
    } else {
        qDebug() << "Query execution error:" << query.lastError().text();
    }
    return results;
}

// Деструктор
DBSingleton::~DBSingleton() {
    db.close();
    qDebug() << "Database connection closed.";
}

// Метод получения экземпляра
DBSingleton* DBSingleton::getInstance() {
    if (!instance) {
        instance = new DBSingleton();
        destroyer.initialize(instance); // Инициализация разрушающего класса
    }
    return instance;
}

// Метод получения базы данных
QSqlDatabase DBSingleton::getDatabase() {
    return db;
}

// Деструктор класса DBSingletonDestroyer
DBSingletonDestroyer::~DBSingletonDestroyer() {
    delete instance; // Удаление экземпляра
}

// Метод инициализации ссылки на экземпляр
void DBSingletonDestroyer::initialize(DBSingleton* link) {
    this->instance = link; // Инициализация ссылки на экземпляр
}
