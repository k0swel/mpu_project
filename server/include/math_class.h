#ifndef math_class_macro
#define math_class_macro
#include <QVector>
#include <QPair>

class math_class {
public:
   math_class() = delete;
   math_class(const math_class&) = delete;
   ~math_class() = delete;
   math_class& operator=(const math_class&) = delete;
   static QVector<QPair<double, double>> diaposons(double a, double b, double step);
   static QVector<double> find_x(const QVector<QPair<double, double>>& diapozon, double a, double b, double c);
   static double Calc(double a, double b, double c, double x); // функция, возвращающая y-значение уравнения
   static bool isZero(double number);
};
#endif
