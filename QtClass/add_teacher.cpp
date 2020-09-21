#include "add_teacher.h"
#include "ui_add_teacher.h"
#include "admin_teacher.h"
add_teacher::add_teacher(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_teacher)
{
    ui->setupUi(this);
    QSqlDatabase db= QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("QtClass.db");
    if ( !db.open())
           qDebug()<<"没有打开！";
}

add_teacher::~add_teacher()
{
    delete ui;
}


//确认添加
void add_teacher::on_pushButton_clicked()
{
    QString addid=ui->NumberlineEdit->text().trimmed();
    QString addPassword=ui->PasswordlineEdit->text().trimmed();
    QString addName=ui->NamelineEdit->text().trimmed();
    QString addSex=ui->SexlineEdit->text().trimmed();
    QString addtel=ui->TellineEdit->text().trimmed();
    QString addyx=ui->YuanxilineEdit->text().trimmed();
    QString addsub=ui->sublineEdit->text().trimmed();

    if(addid.isEmpty()||addName.isEmpty()||addPassword.isEmpty()||addSex.isEmpty()||addtel.isEmpty()||addyx.isEmpty()||addsub.isEmpty()){
        QMessageBox::information(this, "警告", "未完全填写或填写错误");
    }
    else{
        QSqlQuery query;
        //判断输入账户是否存在于数据库中
        query.exec("select id from teacher");
        bool isExist=true;//是否存在
        while(query.next())
       {
           QString id=query.value(0).toString();
           if(id.compare(addid)==0){
               QMessageBox::information(this, "警告", "该账号已存在！");
               isExist=false;
               //this->close();
               break;
           }
           isExist=true;
      }

        if(isExist){
            qDebug()<<"isEXITE="<<isExist;
             QString sql=QString("insert into teacher (id,password,name,sex,yuanxi,subject,phone_number )values('%1','%2','%3','%4','%5','%6','%7')").arg(addid).arg(addPassword).arg(addName).arg(addSex).arg(addyx).arg(addsub).arg(addtel);
             query.exec(sql);
             QMessageBox::information(this, "温馨提示", "恭喜，学号："+addid+"添加成功");
             qDebug()<<addid+"添加成功";
             this->close();
             Admin_teacher *newAdminteacher=new Admin_teacher;
             newAdminteacher->show();
        }

    }
}
//取消
void add_teacher::on_pushButton_2_clicked()
{
    this->close();
    Admin_teacher *newAdminteacher=new Admin_teacher;
    newAdminteacher->show();
}
