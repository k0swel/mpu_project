#include "notification.h"
#include "ui_notification.h"
#include <QTimer>

notification::notification(QString text, QWidget *parent) :
   QWidget(parent),
   ui(new Ui::notification),
   text(text)
{
   ui->setupUi(this);
   this->setWindowFlags(Qt::Tool);
   this->move(0,0); // передвигаем окно в начало виджета.
   ui->label->setText(text); // устанавливаем выбранный текст в уведомление
   ui->label->setWordWrap(true);
   this->show();
   this->setAttribute(Qt::WidgetAttribute::WA_DeleteOnClose); // уничтожаем виджет при его закрытии.
   update_progress_bar();
}

notification::~notification()
{
   qDebug() << "Вызван деструктор уведомления";
   delete ui;
}

void notification::update_progress_bar() {
   timer = new QTimer(this); // инициализируем таймер.
   timer->setInterval(40);
   timer->start();
   connect(timer, &QTimer::timeout, [this]() -> void {
      if (this->ui->progressBar->value() != 100)
         this->ui->progressBar->setValue(++this->current_value_progress_bar);
      else if (this->ui->progressBar->value() == 100) {
         timer->deleteLater(); // уничтожаем таймер
         this->close(); // закрываем текущее окно
      }

   });
}

