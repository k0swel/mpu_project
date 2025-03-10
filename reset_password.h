#ifndef RESET_PASSWORD_H
#define RESET_PASSWORD_H

#include <QWidget>

namespace Ui {
class reset_password;
}

class reset_password : public QWidget
{
   Q_OBJECT

public:
   explicit reset_password(QWidget *parent = nullptr);
   ~reset_password();

private:
   Ui::reset_password *ui;
};

#endif // RESET_PASSWORD_H
