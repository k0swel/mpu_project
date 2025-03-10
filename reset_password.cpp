#include "reset_password.h"
#include "ui_reset_password.h"

reset_password::reset_password(QWidget *parent) :
   QWidget(parent),
   ui(new Ui::reset_password)
{
   ui->setupUi(this);
}

reset_password::~reset_password()
{
   delete ui;
}
