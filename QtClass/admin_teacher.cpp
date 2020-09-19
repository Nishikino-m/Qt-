#include "admin_teacher.h"
#include "ui_admin_teacher.h"

Admin_teacher::Admin_teacher(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Admin_teacher)
{
    ui->setupUi(this);
    this->setWindowTitle("Admin_teacher");
    QIcon icon;
    icon.addFile(":/new/prefix1/Image/Admin.png");
}

Admin_teacher::~Admin_teacher()
{
    delete ui;
}
