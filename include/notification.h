#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <QWidget>
#include <QMouseEvent>

namespace Ui {
class notification;
}

class notification : public QWidget
{
   Q_OBJECT

public:
   static notification* instance; // переменная, которая хранит указатель на единственный виджет уведомления
   static notification* create_instance(QString title, QString text, QWidget *parent = nullptr); // функция, которая создаёт синглтон окна
   notification(const notification&) = delete; // удаляем конструктор копирования
   notification& operator=(const notification&) = delete; // удаляем оператор присваивания
   ~notification();

private slots:
   void on_pushButton_close_clicked(); // кнопка закрытия уведомления

private:
   Ui::notification *ui;
   void update_progress_bar();
   explicit notification(QString title, QString text, QWidget *parent = nullptr);
   int current_value_progress_bar = 0; // значение прогресс бара
   void close_window(); // закрываем окно при нажатии на клавишу
   QTimer* timer; // таймер для прогресс бара
   QString text; // текст для окна.
   void mousePressEvent(QMouseEvent* event) override; // переопределяем событие клика мыши
   void mouseMoveEvent(QMouseEvent* event) override; // переопределяем событие передвижения мыши
   QPoint last_press_position; // переменная хранит последнюю позицию при нажатии на ЛКМ
};

#endif // NOTIFICATION_H
