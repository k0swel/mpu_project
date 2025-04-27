#ifndef FUNCTIONS_FOR_SERVER_H
#define FUNCTIONS_FOR_SERVER_H
#include <QString>
#include <ctime>
#include <QObject>
#include <QList>

class functions_for_server: public QObject
{
   Q_OBJECT
private:
   functions_for_server(); // прячем конструктор
   functions_for_server(const functions_for_server&); // прячем конструктор копирования.
   static functions_for_server* p_instance; // переменная для хранения единственного экземпляра класса
   bool isZero(double number);

public:
   static functions_for_server* get_instance();
   QString get_server_time(); // метод получения времени на сервере.
   void send_email_to_client(QString email, QString code); // функция отправки кода на почту
   QVector<QPair<double, double>> diaposons(double a, double b, double step);
   QVector<double> find_x(const QVector<QPair<double, double>>& diapozon, double a, double b, double c);
   double Calc(double a, double b, double c, double x); // функция, возвращающая y-значение уравнения



signals:
   // ГЛАВНОЕ КЛИЕНТСКОЕ ОКНО
   void signal_equation_solution(QString); // сигнал о решении уравнения

public slots:
   // КЛИЕНТСКОЕ ОКНО
   void slot_linear_equation(QString a, QString b); // функция решения линейного уравнения
   void slot_quadratic_equation(QString a, QString b, QString c); // функция решения квадратного уравнения.
};

#endif // FUNCTIONS_FOR_SERVER_H
