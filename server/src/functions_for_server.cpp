#include "functions_for_server.h"
#include <QDebug>
#include "SmtpMime" // импортируем библиотеку отправки сообщений на почту

functions_for_server* functions_for_server::p_instance = nullptr;

functions_for_server::functions_for_server(){}

void functions_for_server::send_email_to_client(QString email, QString code)
{
   MimeMessage message; // сообщение, которое будет отправлено на почту клиенту
   EmailAddress sender("roma-leonenko@bk.ru", "Roman"); // указываем информацию об отправителе
   EmailAddress receiver(email, "Code for reset password"); // указываем информацию о получателе
   message.setSender(sender);
   message.addRecipient(receiver);
   message.setSubject(QString("Code for receive password")); // указываем тему сообщения

   MimeText text_email;
   text_email.setText(QString("Hi. Here is your password recovery code for your account: %1\nIf you did not request the code, please ignore the message.").arg(code)); // текст, который отправим клиенту)
   message.addPart(&text_email); // прикрепляем наш текст к сообщению, которое будет отправлено на email.
   SmtpClient smtp("smtp.mail.ru", 465, SmtpClient::SslConnection); // создаём объект клиента, который будет подключаться к mail ru
   smtp.connectToHost(); // подключаемся к mail.ru
   if (!smtp.waitForReadyConnected()) {
           qDebug() << "Failed to connect to mail ru!";
           return;
       }
   smtp.login("roma-leonenko@bk.ru", "fv2TpkktaiaimAqKN6iH"); // логинимся под свою учётную запись mail ru
   if (!smtp.waitForAuthenticated()) {
       qDebug() << "Failed to login!";
       return;
   }
   smtp.sendMail(message); // отправляем сообщение
   if (!smtp.waitForMailSent()) { // если соообщение не отправилось
      qDebug() << "Failed to send message";
      return;
   }
   qDebug() << "mail was send successfully!";
   smtp.quit(); // разрываем сеанс с stmp

}

functions_for_server* functions_for_server::get_instance() {
   if (p_instance == nullptr) {
      p_instance = new functions_for_server();
   }
   return p_instance;
}


QString functions_for_server::get_server_time() {
   time_t now_time = time(nullptr); // получаем время на сервере в данный момент.
   tm* time_struct = localtime(&now_time); // конвертируем время в удобную структуру (год, месяц, число, день, час, минута, секунда, миллисекунда)
   char time_format[100];
   strftime(time_format, sizeof(time_format), "[%b %d %Y %H:%M:%S]", time_struct);
   return QString(time_format);
}

QList<QPair<double, double>> functions_for_server::generatePairs(int b) {
    QList<QPair<double, double>> result;

    // Преобразуем int в double
    double start = static_cast<double>(b);

    // Генерируем 5 пар (можно изменить количество)
    for (int i = -b; i < 2 * b; ++i) {
        double first = start + i;
        double second = first + 1.0; // Разница ровно 1 между значениями в паре
        result.append(qMakePair(first, second));
    }

    return result;
}

// Универсальный метод бисекции для f(x) = 0
bool functions_for_server::bisectionMethod(const QPair<double, double>& interval,double c_a, double c_b){
    double tolerance = 0.001;
    double a = interval.first;
    double b = interval.second;
    double fa = c_a * a + c_b;
    double fb = c_a * b + c_b;

    if (fa * fb >= 0) {
        //emit signal_equation_solution("answer|error:no_root_in_interval");
        return false;
    }

    int iterations = 0;
    const int max_iterations = 1000;
    double c = a;

    while ((b - a) >= tolerance && iterations < max_iterations) {
        c = (a + b) / 2;
        double fc = c_a * c + c_b;

        if (qFuzzyIsNull(fc)) break;

        if (fc * fa < 0) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }
        iterations++;
    }

    QString solution = QString("answer|%1").arg(c).arg(iterations);
    emit signal_equation_solution(solution);
    return true;
}


void functions_for_server::slot_linear_equation(QString a, QString b)
{
    bool ok1, ok2;
    double coeff_a = a.toDouble(&ok1);
    double coeff_b = b.toDouble(&ok2);
    QString solution;

    if (!ok1 || !ok2) {
        solution = "answer|error:invalid_input";
        emit this->signal_equation_solution(solution);
        return;
    }

    // a = 0
    if (qFuzzyIsNull(coeff_a)) {
        if (qFuzzyIsNull(coeff_b)) {
            solution = "answer|infinite_solutions"; // 0x = 0
        } else {
            solution = "answer|no_solution"; // 0x = b (where b ≠ 0)
        }
    } else {
        // ax + b = 0 → x = -b/a
        double answer = -coeff_b / coeff_a;
        solution = QString("answer|%1").arg(answer);
    }

    emit this->signal_equation_solution(solution);
}

void functions_for_server::slot_quadratic_equation(QString a, QString b, QString c)
{
    bool ok1, ok2, ok3;
    double coeff_a = a.toDouble(&ok1);
    double coeff_b = b.toDouble(&ok2);
    double coeff_c = c.toDouble(&ok3);
    QString solution;

    if (!ok1 || !ok2 || !ok3) {
        solution = "answer|error:invalid_input";
        emit this->signal_equation_solution(solution);
        return;
    }

// Является ли коэффициент у x^2 нулевым
    if (qFuzzyIsNull(coeff_a)) {
        // Квадратное уравнение становится линейным
        if (qFuzzyIsNull(coeff_b)) {
            if (qFuzzyIsNull(coeff_c)) {
                solution = "answer|infinite_solutions"; // 0 = 0
            } else {
                solution = "answer|no_solution"; // c = 0 где c ≠ 0
            }
        } else {
            double root = -coeff_c / coeff_b;
            solution = QString("answer|%1").arg(root);
        }
        emit this->signal_equation_solution(solution);
        return;
    }

    // Вычисляем дискриминант
    double discriminant = coeff_b * coeff_b - 4 * coeff_a * coeff_c;

    if (discriminant > 0) {
        double root1 = (-coeff_b + sqrt(discriminant)) / (2 * coeff_a);
        double root2 = (-coeff_b - sqrt(discriminant)) / (2 * coeff_a);
        solution = QString("answer|%1$%2").arg(root1).arg(root2);
    }
    else if (qFuzzyIsNull(discriminant)) {
        double root = -coeff_b / (2 * coeff_a);
        solution = QString("answer|%1").arg(root);
    }
    else {
        double realPart = -coeff_b / (2 * coeff_a);
        double imaginaryPart = sqrt(-discriminant) / (2 * coeff_a);
        solution = QString("answer|complex:%1+%2i$%1-%2i")
                       .arg(realPart)
                       .arg(imaginaryPart);
    }

    emit this->signal_equation_solution(solution);
}
