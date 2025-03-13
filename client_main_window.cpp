#include "client_main_window.h"
#include "ui_client_main_window.h"

client_main_window::client_main_window(QWidget *parent) :
   QMainWindow(parent),
   ui(new Ui::client_main_window)
{
   ui->setupUi(this);
}

client_main_window::~client_main_window()
{
   delete ui;
}
