#ifndef REG_FORM_H
#define REG_FORM_H

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
   auth_form* window_auth = nullptr;
   reset_password* window_reset = nullptr;
   void reset_text();
};
#endif // REG_FORM_H
