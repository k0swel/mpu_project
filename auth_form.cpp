#include "auth_form.h"
#include "ui_auth_form.h"

auth_form::auth_form(QWidget *parent) :
   QWidget(parent),
   ui(new Ui::auth_form)
{
   ui->setupUi(this);
}

auth_form::~auth_form()
{
   delete ui;
}
