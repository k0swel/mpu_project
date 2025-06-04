#include "math_class.h"

QVector<QPair<double, double>> math_class::diaposons(double a, double b, double step) {
    QVector<QPair<double, double>> diaposon;
    double a_start = a;
    double b_start = a + step;
    while (a_start + step <= b) {
        diaposon.push_back({ a_start, b_start });
        a_start = b_start;
        b_start += step;
    }
    return diaposon;
}

bool math_class::isZero(double number)
{
   return (number >=0 and number < 0.0001);
}

QVector<double> math_class::find_x(const QVector<QPair<double, double>>& diapozon,
                                           double a, double b, double c) {
    QVector<double> answers;
    const double EPS = 1e-10;

    for (auto interval : diapozon) {
        double x1 = interval.first;
        double x2 = interval.second;
        double f1 = Calc(a, b, c, x1);
        double f2 = Calc(a, b, c, x2);

        // Проверка корня на левой границе
        if (isZero(f1)) {
            if (answers.empty() || !qFuzzyCompare(answers.last(), x1)) {
                answers.push_back(x1);
            }
            continue;
        }

        // Проверка корня на правой границе
        if (isZero(f2)) {
            if (answers.empty() || !qFuzzyCompare(answers.last(), x2)) {
               answers.push_back(x2);
            }
            continue;
        }


        // Поиск корня внутри интервала
        if (f1 * f2 < 0) {
            while (qAbs(x2 - x1) > EPS) {
                double mid = (x1 + x2) / 2;
                double f_mid = Calc(a, b, c, mid);

                if (isZero(f_mid)) {
                    break;
                }

                if (f1 * f_mid < 0) {
                    x2 = mid;
                    f2 = f_mid;
                } else {
                    x1 = mid;
                    f1 = f_mid;
                }
            }

            double root = (x1 + x2) / 2;
            if (answers.empty() || !qFuzzyCompare(answers.last(), root)) {
                answers.push_back(root);
            }
        }
    }

    return answers;
}

double math_class::Calc(double a, double b, double c, double x){
    return x*x*a + x*b + c;
}

