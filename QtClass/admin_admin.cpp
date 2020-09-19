#include "admin_admin.h"
#include "ui_admin_admin.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QtSql>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QClipboard>
Admin_admin::Admin_admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Admin_admin)
{
    ui->setupUi(this);
    QSqlDatabase db= QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("QtClass.db");
    if (!db.open()){
           qDebug()<<"没有打开！";
       }

    //初始管理员admin admin
    QSqlQuery query;
    query.exec("select admin_account from admin");
        if(!query.next()){
                query.exec("INSERT INTO admin (admin_account, admin_password) "
                               "VALUES ('admin','admin')");
        }
    QSqlQueryModel *model = new QSqlQueryModel(this);
       model->setQuery("select admin_account,admin_password from admin");

       model->setHeaderData(0,Qt::Horizontal,tr("账号"));
       model->setHeaderData(1,Qt::Horizontal,tr("密码"));
       ui->tableView->setModel(model);
}

Admin_admin::~Admin_admin()
{
    delete ui;
}


//添加管理员
void Admin_admin::on_add_clicked()
{
    QString wantAddAdminAccount=ui->lineEdit->text();
    QString wantAddAdminPassword=ui->lineEdit_2->text();
    //判断输入学号是否存在于数据库中
    QSqlQuery query;
    query.exec("select admin_account from admin");
    bool isExist=false;//是否存在
    if(wantAddAdminAccount==""||wantAddAdminPassword==""){QMessageBox::information(this, "警告", "账号或密码不能为空！");return;}
    while(query.next())
               {
                   QString AddAdminAccount=query.value(0).toString();
                   if(wantAddAdminAccount.compare(AddAdminAccount)==0){
                       QMessageBox::information(this, "WARNING", "该账号已存在！");
                       isExist=false;
                       //this->close();
                       ui->lineEdit->setText("");
                       ui->lineEdit_2->setText("");
                       break;
                   }
                   isExist=true;
              }
    if(isExist){
                 QString sql=QString("insert into admin(admin_account,admin_password)values('%1','%2')").arg(wantAddAdminAccount).arg(wantAddAdminPassword);
                 query.exec(sql);
                 QMessageBox::information(this, "温馨提示", "添加成功！新增管理员："+wantAddAdminAccount);
                 qDebug()<<wantAddAdminAccount+"添加成功";
              //界面主动刷新
                 //this->hide();
                 this->close();
                 Admin_admin *newAdminAdminShow=new Admin_admin;
                 newAdminAdminShow->show();
    }
}

//删除
void Admin_admin::on_sub_clicked()
{
    QString wantDeleteAdminId=ui->lineEdit_3->text();
    //判断输入想要删除的班级是否存在于数据库中
    QSqlQuery query;
    bool isExist=false;//是否存在
    query.exec("select admin_account from admin");
    while(query.next())
               {
                   QString tempAdminId=query.value(0).toString();
                   if(tempAdminId.compare(wantDeleteAdminId)==0){
                       QString sql=QString("delete from admin where admin_account='%1'").arg(wantDeleteAdminId);
                       query.exec(sql);
                        QMessageBox::information(this, "温馨提示", "恭喜，管理员："+wantDeleteAdminId+"删除成功");
                       qDebug()<<wantDeleteAdminId+"删除成功";
                       isExist=false;
                       //界面主动刷新
                       //this->hide();//这是隐藏
                       this->close();//这是直接关闭
                       Admin_admin *newAdminAdminShow=new Admin_admin;
                       newAdminAdminShow->show();
                       //this->close();
                       break;
                   }
                   isExist=true;
              }
    if(isExist){
                  QMessageBox::information(this, "WARNING", "抱歉，不存在账号为："+wantDeleteAdminId+"的管理员");
                 qDebug()<<wantDeleteAdminId+"删除失败";
                 //this->close();
                 ui->lineEdit_3->setText("");
    }

}
//单击可选择内容复制
void Admin_admin::on_tableView_clicked(const QModelIndex &index)
{
    QString tableViewValue=index.data().toString();
    QClipboard *board=QApplication::clipboard();
       board->setText(tableViewValue);
       QMessageBox::information(this, "温馨提示", "信息"+tableViewValue+"已复制到粘贴板");
}
