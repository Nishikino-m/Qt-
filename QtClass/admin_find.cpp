#include "admin_find.h"
#include "ui_admin_find.h"

Admin_find::Admin_find(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Admin_find)
{
    ui->setupUi(this);
    this->setWindowTitle("Admin_find");
    QIcon icon;
    icon.addFile(":/new/prefix1/Image/Admin.png");
}

Admin_find::~Admin_find()
{
    delete ui;
}
