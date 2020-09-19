#include "student.h"
#include "ui_student.h"
#include "uandp.h"
#include "login.h"
Student::Student(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Student)
{
    ui->setupUi(this);
    this->setWindowTitle("Student");
    QIcon icon;
    icon.addFile(":/new/prefix1/Image/Admin.png");
    ui->label_user->setText("当前账户："+Login_Username);
    ui->pushButton->setStyleSheet("border:none;");
    ui->pushButton_2->setStyleSheet("border:none;");



    QSqlDatabase db= QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("QtClass.db");
    if ( !db.open()){
           qDebug()<<"没有打开！";
       }
    QSqlQuery query;
    QString sql=QString("select name,number,sex,tel,yuanxi,zhuanye,qinshi,class from student where id='%1'").arg(Login_Username);
    query.exec(sql);
    while (query.next()) {
        QString Student_name=query.value(0).toString();
        QString Student_number=query.value(1).toString();
        QString Student_sex=query.value(2).toString();
        QString Student_tel=query.value(3).toString();
        QString Student_yuanxi=query.value(4).toString();
        QString Student_zhuanye=query.value(5).toString();
        QString Student_qinShi=query.value(6).toString();
        QString Student_class=query.value(7).toString();
        ui->NamelineEdit->setText(Student_name);
        ui->NumberlineEdit->setText(Student_number);
        ui->SexlineEdit->setText(Student_sex);
        ui->TellineEdit->setText(Student_tel);
        ui->YuanxilineEdit->setText(Student_yuanxi);
        ui->ZhuanyelineEdit->setText(Student_zhuanye);
        ui->QinshilineEdit->setText(Student_qinShi);
        ui->ClasslineEdit->setText(Student_class);
    }
}

Student::~Student()
{
    delete ui;
}


//修改信息
void Student::on_pushButton_clicked()
{
    QString Update_name=ui->NamelineEdit->text();
    QString Update_number=ui->NumberlineEdit->text();
    QString Update_sex=ui->SexlineEdit->text();
    QString Update_tel=ui->TellineEdit->text();
    QString Update_yuanxi=ui->YuanxilineEdit->text();
    QString Update_zhuanye=ui->ZhuanyelineEdit->text();
    QString Update_qinshi=ui->QinshilineEdit->text();
    QString Update_class=ui->ClasslineEdit->text();
    if(Update_name.isEmpty()||Update_number.isEmpty()||Update_sex.isEmpty()||Update_tel.isEmpty()||Update_yuanxi.isEmpty()||Update_zhuanye.isEmpty()||Update_qinshi.isEmpty()||Update_class.isEmpty()){
        QMessageBox::information(this, "Warning", "信息未填写完整或有误");
    }
    else{
        QSqlQuery query;
        QString UpdateUser=Login_Username;
        QString sql=QString("update student set name='%1',number='%2',sex='%3',tel='%4',yuanix='%5',zhuanye='%6',qinshi='%7',class='%8' where id='%9'").arg(Update_name).arg(Update_number).arg(Update_sex).arg(Update_tel).arg(Update_yuanxi).arg(Update_zhuanye).arg(Update_qinshi).arg(Update_class).arg(UpdateUser);
        query.exec(sql);
        QMessageBox::information(this, "温馨提示", "恭喜！您的信息修改成功！需要重新登录");
        qDebug()<<"修改成功";
        this->close();
        Login *login=new Login;
        login->show();
    }
}

//退出系统
void Student::on_pushButton_2_clicked()
{
    this->close();
    Login *login=new Login;
    login->show();
}
