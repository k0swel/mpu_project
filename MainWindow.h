#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QApplication>
#include <QScreen>
#include "client.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
   Q_OBJECT

public:
   Widget(QWidget *parent = nullptr);
   ~Widget();

private slots:
   void on_pushButton_reg_clicked();

private:
   Ui::Widget *ui;
   Client this_client;
};
#endif // MAINWINDOW_H
