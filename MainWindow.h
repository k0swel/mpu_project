#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QApplication>
#include <QScreen>
#include "client.h"
#include "auth_form.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
   Q_OBJECT

public:
   Widget(Client* client, QWidget *parent = nullptr);
   ~Widget();

private slots:
   void on_pushButton_reg_clicked();

   void on_toolButton_auth_clicked();

private:
   Ui::Widget *ui;
   Client* client;
   auth_form* authorization = nullptr;
};
#endif // MAINWINDOW_H
