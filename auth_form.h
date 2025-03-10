#ifndef AUTH_FORM_H
#define AUTH_FORM_H

#include <QWidget>

namespace Ui {
class auth_form;
}

class auth_form : public QWidget
{
   Q_OBJECT

public:
   explicit auth_form(QWidget *parent = nullptr);
   ~auth_form();

private:
   Ui::auth_form *ui;
};

#endif // AUTH_FORM_H
