#include "change_student.h"
#include "ui_change_student.h"
#include "admin_student.h"
change_student::change_student(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::change_student)
{
    ui->setupUi(this);
    QSqlDatabase db= QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("QtClass.db");
    if ( !db.open()){
           qDebug()<<"没有打开！";
       }
}

change_student::~change_student()
{
    delete ui;
}
bool ifNotFindIdDo=true;
//更新修改数据
void change_student::on_pushButton_2_clicked()
{
   if(ifNotFindIdDo){ QMessageBox::information(this, "警告", "请先输入学号");return;}
   QString updateId=ui->idlineEdit->text().trimmed();
   QString updatePassword=ui->passwordlineEdit->text().trimmed();
   QString updateName=ui->NamelineEdit->text().trimmed();
   QString updateSex=ui->SexlineEdit->text().trimmed();
   QString updateyuanxi=ui->yuanxilineEdit->text().trimmed();
   QString updatezhuanye=ui->zhuanyelineEdit->text().trimmed();
   QString updatePhone_number=ui->tellineEdit->text().trimmed();
   QString updateDormitory=ui->qinshilineEdit->text().trimmed();
   QString updateClassName=ui->classlineEdit->text().trimmed();

   if(updateId.isEmpty()||updateName.isEmpty()||updatePassword.isEmpty()||updateSex.isEmpty()||updateyuanxi.isEmpty()||updatezhuanye.isEmpty()||updatePhone_number.isEmpty()||updateDormitory.isEmpty()||updateClassName.isEmpty()){
       QMessageBox::information(this, "警告", "未完全填写或填写错误");
   }
   else{
       QSqlQuery query;
       QString wantUpdateStudentId=ui->ChangeidlineEdit->text().trimmed();
       QString sql=QString("update student set id='%1',password='%2',name='%3',sex='%4',yuanxi='%5',zhuanye='%6',phone_number='%7',dormitory='%8',className='%9' where id='%10'").arg(updateId).arg( updatePassword).arg( updateName).arg( updateSex).arg( updateyuanxi).arg( updatezhuanye).arg( updatePhone_number).arg( updateDormitory).arg( updateClassName).arg(wantUpdateStudentId);
       query.exec(sql);
       QMessageBox::information(this, "温馨提示", "恭喜！信息修改成功！");
       qDebug()<<"修改成功";
       this->close();
       Admin_Student *newAdminStudentShow=new Admin_Student;
       newAdminStudentShow->show();
    }
}
//想要更改的学生学号
void change_student::on_pushButton_clicked()
{
      QString wantUpdateStudentId=ui->ChangeidlineEdit->text();
      QSqlQuery query;
      //判断输入学号是否存在于数据库中
      QString sql=QString("select id from student where id='%1'").arg(wantUpdateStudentId);
      query.exec(sql);
      bool isExist=false;//是否存在
      while(query.next())
                 {
                     QString id=query.value(0).toString();
                     if(id.compare(wantUpdateStudentId)==0){
                         ifNotFindIdDo=false;
                         isExist=true;
                         //this->close();
                         break;
                     }
                     isExist=false;
                }
      if(isExist){
          QSqlQuery query;
          QString sql=QString("select id,password,name,sex,yuanxi,zhuanye,phone_number,dormitory,className from student where id='%1'").arg(wantUpdateStudentId);
          query.exec(sql);
          while (query.next()) {
              QString Update_id=query.value(0).toString();
              QString Update_password=query.value(1).toString();
              QString Update_name=query.value(2).toString();
              QString Update_sex=query.value(3).toString();
              QString Update_yuanxi=query.value(4).toString();
              QString Update_zhuanye=query.value(5).toString();
              QString Update_phone_number=query.value(6).toString();
              QString Update_dormitory=query.value(7).toString();
              QString Update_className=query.value(8).toString();
              ui->ChangeidlineEdit->setText(Update_id);
              ui->idlineEdit->setText(Update_id);
              ui->passwordlineEdit->setText(Update_password);
              ui->NamelineEdit->setText(Update_name);
              ui->SexlineEdit->setText(Update_sex);
              ui->yuanxilineEdit->setText(Update_yuanxi);
              ui->zhuanyelineEdit->setText(Update_zhuanye);
              ui->tellineEdit->setText(Update_phone_number);
              ui->qinshilineEdit->setText(Update_dormitory);
              ui->classlineEdit->setText(Update_className);
          }

      }
      else{
          QMessageBox::information(this, "WARNING", "请检查学号是否输入正确！");
      }

}
//取消更新学生信息
void change_student::on_pushButton_3_clicked()
{
   this->close();
   Admin_Student *newAdminStudentShow=new Admin_Student;
   newAdminStudentShow->show();
}
