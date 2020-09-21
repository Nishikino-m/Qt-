#include "add_student.h"
#include "ui_add_student.h"
#include "admin_student.h"
#include "headers.h"
Add_Student::Add_Student(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add_Student)
{
    ui->setupUi(this);
    QSqlDatabase db= QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("QtClass.db");
    if ( !db.open())
           qDebug()<<"没有打开！";
}

Add_Student::~Add_Student()
{
    delete ui;
}


//确认添加
void Add_Student::on_pushButton_clicked()
{
    QString addid=ui->NumberlineEdit->text().trimmed();
    QString addPassword=ui->PasswordlineEdit->text().trimmed();
    QString addName=ui->NamelineEdit->text().trimmed();
    QString addSex=ui->SexlineEdit->text().trimmed();
    QString addtel=ui->TellineEdit->text().trimmed();
    QString addyx=ui->YuanxilineEdit->text().trimmed();
    QString addzy=ui->ZhuanyelineEdit->text().trimmed();
    QString addqs=ui->QinshilineEdit->text().trimmed();
    QString addClass=ui->ClasslineEdit->text().trimmed();
    if(addid.isEmpty()||addName.isEmpty()||addPassword.isEmpty()||addSex.isEmpty()||addtel.isEmpty()||addyx.isEmpty()||addqs.isEmpty()||addClass.isEmpty()||addzy.isEmpty()){
        QMessageBox::information(this, "WARNING", "未完全填写或填写错误");
    }else{
        QSqlQuery query;
        //判断输入账户是否存在于数据库中
        query.exec("select id from student");
        bool isExist=false;//是否存在
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
     //一开始没有任何数据的情况下，query.next()不会执行，所以会出现无响应情况，增加!query.next()，让第一个增加的数据能增加成功
        if(!query.next()){
            isExist=true;
        }
        if(isExist){
             QString sql=QString("insert into student(id,password,name,sex,yuanxi,zhuanye,phone_number,dormitory,className)values('%1','%2','%3','%4','%5','%6','%7','%8','%9')").arg(addid).arg(addPassword).arg(addName).arg(addSex).arg(addyx).arg(addzy).arg(addtel).arg(addqs).arg(addClass);
             query.exec(sql);
             QMessageBox::information(this, "温馨提示", "恭喜，学号："+addid+"添加成功");
             qDebug()<<addid+"添加成功";
             this->close();
             Admin_Student *newAdminStudent=new Admin_Student;
             newAdminStudent->show();
        }

}
}
//取消
void Add_Student::on_pushButton_2_clicked()
{
    this->close();
    Admin_Student *newAdminStudent=new Admin_Student;
    newAdminStudent->show();
}
