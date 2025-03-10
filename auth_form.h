#ifndef AUTH_FORM_H
#define AUTH_FORM_H

#include <QWidget>
#include "client.h"

namespace Ui {
class auth_form;
}

class auth_form : public QWidget
{
   Q_OBJECT

public:
   explicit auth_form(Client* client_socket, QWidget *parent = nullptr);
   ~auth_form();

private slots:
   void on_pushButton_login_clicked();

private:
   Ui::auth_form *ui;
   Client* client;
};

#endif // AUTH_FORM_H
