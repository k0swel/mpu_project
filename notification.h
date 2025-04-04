#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <QWidget>

namespace Ui {
class notification;
}

class notification : public QWidget
{
   Q_OBJECT

public:
   explicit notification(QString title, QString text, QWidget *parent = nullptr);
   ~notification();

private:
   Ui::notification *ui;
   void update_progress_bar();
   int current_value_progress_bar = 0; // значение прогресс бара
   QTimer* timer; // таймер для прогресс бара
   QString text; // текст для окна.
};

#endif // NOTIFICATION_H
