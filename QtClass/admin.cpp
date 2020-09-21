#include "admin.h"
#include "ui_admin.h"
#include "login.h"
#include "uandp.h"
#include "headers.h"
Admin::Admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);
    this->setWindowTitle("Admin");
    QIcon icon;
    icon.addFile(":/new/prefix1/Image/Admin.png");
    ui->label->setText("当前管理员："+Login_Username);
    ui->pushButton->setStyleSheet("border:none;");
    ui->pushButton_2->setStyleSheet("border:none;");
    ui->pushButton_3->setStyleSheet("border:none;");
    ui->pushButton_4->setStyleSheet("border:none;");
    ui->pushButton_5->setStyleSheet("border:none;");
    //ui->label_2->setPixmap(QPixmap(":/new/prefix1/Image/Adminer.jpg"));
     ui->label_2->setScaledContents(true);
}

Admin::~Admin()
{
    delete ui;
}
//student表
void Admin::on_pushButton_clicked()
{
    studentTable=new Admin_Student ;
    studentTable->setModal(true);
    studentTable->show();
    qDebug()<<"STUDENT";
}
//teacher表
void Admin::on_pushButton_2_clicked()
{
    teacherTable=new Admin_teacher ;
    teacherTable->setModal(true);
    teacherTable->show();

    qDebug()<<"TEACHER";
}
//admin表
void Admin::on_pushButton_3_clicked()
{
    adminTable=new Admin_admin;
     adminTable->setModal(true);
     adminTable->show();
    qDebug()<<"ADMIN";
}
//快速查找
void Admin::on_pushButton_4_clicked()
{
    findTable=new Admin_find;
    findTable->setModal(true);
    findTable->show();
    qDebug()<<"find";
}
//退出管理员界面
void Admin::on_pushButton_5_clicked()
{
    this->close();
    Login *login=new Login;
    login->show();

}
