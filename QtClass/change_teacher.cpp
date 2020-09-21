#include "change_teacher.h"
#include "ui_change_teacher.h"
#include "headers.h"
#include "admin_teacher.h"
change_teacher::change_teacher(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::change_teacher)
{
    ui->setupUi(this);
    QSqlDatabase db= QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("QtClass.db");
    if ( !db.open()){
           qDebug()<<"没有打开！";
       }
}

change_teacher::~change_teacher()
{
    delete ui;
}


bool isFindid=true;
//更新修改数据
void change_teacher::on_pushButton_2_clicked()
{
    if(isFindid){ QMessageBox::information(this, "警告", "请先输入学号");return;}
    QString updateId=ui->idlineEdit->text().trimmed();
    QString updatePassword=ui->passwordlineEdit->text().trimmed();
    QString updateName=ui->namelineEdit->text().trimmed();
    QString updateSex=ui->SexlineEdit->text().trimmed();
    QString updateyuanxi=ui->yuanxilineEdit->text().trimmed();
    QString updatePhone_number=ui->tellineEdit->text().trimmed();
    QString updatesubject=ui->sublineEdit->text().trimmed();
    if(updateId.isEmpty()||updateName.isEmpty()||updatePassword.isEmpty()||updateSex.isEmpty()||updateyuanxi.isEmpty()||updatePhone_number.isEmpty()||updatesubject.isEmpty()){
       QMessageBox::information(this, "警告", "未完全填写或填写错误");
    }else{
       QSqlQuery query;
       QString Changeuser=ui->lineEdit->text();
       QString sql=QString("update teacher set id='%1',password='%2',name='%3',sex='%4',yuanxi='%5',subject='%6',phone_number='%7' where id='%10'").arg(updateId).arg( updatePassword).arg( updateName).arg( updateSex).arg( updateyuanxi).arg( updatesubject).arg( updatePhone_number).arg(Changeuser);
       query.exec(sql);
       QMessageBox::information(this, "温馨提示", "恭喜！信息修改成功！");
       qDebug()<<"修改成功";
       this->close();
       Admin_teacher *newAdminteacher=new Admin_teacher;
       newAdminteacher->show();
    }
}
//想要更改的学生学号
void change_teacher::on_pushButton_clicked()
{
  QString Changeuser=ui->lineEdit->text().trimmed();
  QSqlQuery query;
  //判断输入学号是否存在于数据库中
  QString sql=QString("select id from teacher where id='%1'").arg(Changeuser);
  query.exec(sql);
  bool isExist=false;//是否存在
  while(query.next())
             {
                 QString id=query.value(0).toString();
                 if(id.compare(Changeuser)==0){
                     isFindid=false;
                     isExist=true;
                     //this->close();
                     break;
                 }
                 isExist=false;
            }
  if(isExist){
      QSqlQuery query;
      QString sql=QString("select id,password,name,sex,yuanxi,subject,phone_number from teacher where id='%1'").arg(Changeuser);
      query.exec(sql);
      while (query.next()) {
          QString Update_id=query.value(0).toString();
          QString Update_password=query.value(1).toString();
          QString Update_name=query.value(2).toString();
          QString Update_sex=query.value(3).toString();
          QString Update_yuanxi=query.value(4).toString();
          QString Update_phone_number=query.value(6).toString();
          QString Update_subject=query.value(5).toString();
          ui->idlineEdit->setText(Update_id);
          ui->passwordlineEdit->setText(Update_password);
          ui->namelineEdit->setText(Update_name);
          ui->SexlineEdit->setText(Update_sex);
          ui->yuanxilineEdit->setText(Update_yuanxi);
          ui->tellineEdit->setText(Update_phone_number);
          ui->sublineEdit->setText(Update_subject);
      }

  }
  else{
      QMessageBox::information(this, "WARNING", "请检查学号是否输入正确！");
  }

}
//取消更新学生信息
void change_teacher::on_pushButton_3_clicked()
{
    this->close();
    Admin_teacher *newAdminteacher=new Admin_teacher;
    newAdminteacher->show();
}
