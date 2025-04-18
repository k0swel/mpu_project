#include "notification.h"
#include "ui_notification.h"
#include <QTimer>

notification::notification(QString title, QString text, QWidget *parent) :
   QWidget(parent),
   ui(new Ui::notification),
   text(text)
{
   ui->setupUi(this);
   this->setWindowFlags(Qt::Tool);
   this->setWindowTitle(title); // устанавливаем заголовок окна
   this->move(0,0); // передвигаем окно в начало рабочего стола.
   ui->label->setText(text); // устанавливаем выбранный текст в уведомление
   ui->label->setWordWrap(true); // делаем перенос qlabel на новую строку при необходимости.
   this->show(); // отображаем уведомление
   this->setAttribute(Qt::WidgetAttribute::WA_DeleteOnClose); // уничтожаем виджет при его закрытии.
   update_progress_bar(); // функция обновления прогресс бара.
}

notification::~notification()
{
   qDebug() << "Вызван деструктор уведомления";
   delete ui;
}

void notification::update_progress_bar() {
   timer = new QTimer(this); // инициализируем таймер.
   timer->setInterval(20); // устанавливаем интервал 0,020 секунд
   timer->start(); // запускаем таймер
   connect(timer, &QTimer::timeout, [this]() -> void {
      if (this->ui->progressBar->value() != 100)
         this->ui->progressBar->setValue(++this->current_value_progress_bar);
      else if (this->ui->progressBar->value() == 100) {
         timer->deleteLater(); // уничтожаем таймер
         this->close_window(); // закрываем текущее окно
      }

   });
}

void notification::close_window()
{
   qreal start_opacity = 1;
   while (start_opacity > 0) {
      start_opacity-= 0.0001;
      this->setWindowOpacity(start_opacity);
   }
   this->close(); // закрываем окно
}

