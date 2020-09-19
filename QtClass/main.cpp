#include "mainwindow.h"
#include "login.h"
#include <QApplication>
#include"admin_admin.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //创建数据库
    QSqlDatabase db= QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("QtClass.db");
    if ( !db.open()){
           qDebug()<<"没有打开！";
       }
    QSqlQuery query;//QSqlQuery类提供执行和操作的SQL语句的方法
  //创建数据库admin表
    query.exec("CREATE TABLE admin ("
                       "admin_account VARCHAR(40) PRIMARY KEY NOT NULL,"
                       "admin_password VARCHAR(40) NOT NULL)");

    //创建数据库student表
        query.exec("CREATE TABLE student ("
                       "id VARCHAR(50) PRIMARY KEY NOT NULL, "
                       "name VARCHAR(30) NOT NULL, "
                       "sex VARCHAR(10) NOT NULL, "
                       "age INTEGER NOT NULL,"
                       "address VARCHAR(50) NOT NULL,"
                       "phone_number VARCHAR(30) NOT NULL,"
                       "password VARCHAR(30) NOT NULL,"
                       "dormitory VARCHAR(30) NOT NULL,"
                       "className VARCHAR(30) NOT NULL)");

    //创建数据库class表
    query.exec("CREATE TABLE class ("
                       "name VARCHAR(40) PRIMARY KEY NOT NULL, "
                       "department VARCHAR(50) NOT NULL, "
                       "instructor VARCHAR(40) NOT NULL, "
                       "instructor_number VARCHAR(40) NOT NULL,"
                        "people_number INTEGER NOT NULL)");
    //初始化创建一个管理员账户：admin admin
    Admin_admin *admin_admin=new Admin_admin;
    admin_admin->hide();
    Login l;



    l.setWindowTitle("LOGIN");
    if (l.exec() == QDialog::Accepted)//调用login.exec()，阻塞主控制流，直到完成返回，继续执行主控制流
    {
        qDebug()<<"aaa";
       return a.exec();

    }
    return 0;
    //return a.exec();
}
