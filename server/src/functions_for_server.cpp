#include "functions_for_server.h"
#include <QDebug>
#include "SmtpMime" // импортируем библиотеку отправки сообщений на почту
#include "math_class.h"

functions_for_server* functions_for_server::p_instance = nullptr;

functions_for_server::functions_for_server(){}

bool functions_for_server::send_email_to_client(QString email, QString code)
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
        qCritical() << "Failed to connect to mail ru!";
         smtp.quit(); // разрываем сеанс с stmp
        return false;
   }
   smtp.login("roma-leonenko@bk.ru", "fv2TpkktaiaimAqKN6iH"); // логинимся под свою учётную запись mail ru
   if (!smtp.waitForAuthenticated()) {
       qCritical() << "Failed to login!";
       smtp.quit(); // разрываем сеанс с stmp
       return false;
   }
   smtp.sendMail(message); // отправляем сообщение
   if (!smtp.waitForMailSent()) { // если соообщение не отправилось
      qCritical() << "Failed to send message";
      smtp.quit(); // разрываем сеанс с stmp
      return false;
   }
   qCritical() << "mail was send successfully!";
   return true;

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

void functions_for_server::slot_linear_equation(QString a, QString b, client* client)
{
    bool ok1, ok2;
    double coeff_a = a.toDouble(&ok1);
    double coeff_b = b.toDouble(&ok2);
    QString solution;

    if (!ok1 or !ok2) {
        solution = "answer|error";
        QMetaObject::invokeMethod(client, "slot_equation_solution", Q_ARG(QString, solution));
        //emit this->signal_equation_solution(solution);
        return;
    }

    // a = 0
    if (qFuzzyIsNull(coeff_a)) {
        if (qFuzzyIsNull(coeff_b)) {
            solution = "answer|infinity_solutions"; // 0x = 0
        } else {
            solution = "answer|no_solution"; // 0x = b (b ≠ 0)
        }
    } else {
        // Определяем диапазон и шаг
        QVector<QPair<double, double>> ans = math_class::diaposons(-1000, 1000, 1);
        QVector<double> korni = math_class::find_x(ans, 0, coeff_a, coeff_b);
        //Выводим корни
        solution = QString("answer|");
        for (const auto &el : korni) {
            solution.append(QString::number(el, 'g', 2));
            solution.append("$");
        }
        solution.chop(1);
        double answer = -coeff_b / coeff_a;
        solution = QString("answer|%1").arg(answer);
    }
    QMetaObject::invokeMethod(client, "slot_equation_solution", Q_ARG(QString, solution));
    //emit this->signal_equation_solution(solution);
}

void functions_for_server::slot_quadratic_equation(QString a, QString b, QString c, client* client)
{
    bool ok1, ok2, ok3;
    double coeff_a = a.toDouble(&ok1);
    double coeff_b = b.toDouble(&ok2);
    double coeff_c = c.toDouble(&ok3);
    QString solution;

    if (!ok1 || !ok2 || !ok3) {
       // некорректный ввод
        solution = "answer|error";
        QMetaObject::invokeMethod(client, "slot_equation_solution", Q_ARG(QString, solution));
        //emit this->signal_equation_solution(solution);
        return;
    }
    if (qFuzzyIsNull(coeff_a) && qFuzzyIsNull(coeff_b))
    {
        if (qFuzzyIsNull(coeff_c)) {
           // бесконечное число решений
           QMetaObject::invokeMethod(client, "slot_equation_solution", Q_ARG(QString, solution));
           //emit this->signal_equation_solution("answer|infinity_solutions");
            return;
        }
        // нет корней
        emit this->signal_equation_solution("answer|no_solution");
        return;
    }
    QVector<QPair<double, double>> ans = math_class::diaposons(-1000, 1000, 0.1);
    QVector<double> korni = math_class::find_x(ans, coeff_a, coeff_b, coeff_c);
    //Выводим корни
    solution = QString("answer|");
    if (korni.size() > 0) {
       for (const auto &el : korni) {
           solution.append(QString::number(el, 'f', 4));
           solution.append("$");
       }
       solution.chop(1);
    }
    else {
       // корней нет.
       solution = QString("answer|no_solution");
    }
    QMetaObject::invokeMethod(client, "slot_equation_solution", Q_ARG(QString, solution));
    //emit this->signal_equation_solution(solution);
}
