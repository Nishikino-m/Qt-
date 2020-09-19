#include "login.h"
#include <QApplication>
#include"admin_admin.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QtSql>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QClipboard>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
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
                       //"admin_else VARCHAR(40)  NOT NULL)"

    //创建数据库student表
        query.exec("CREATE TABLE student ("
                       "id VARCHAR(50) PRIMARY KEY NOT NULL, "
                       "password VARCHAR(30) NOT NULL"
                       "name VARCHAR(30) NOT NULL, "
                       "number VARCHAR(30) NOT NULL, "
                       "sex VARCHAR(10) NOT NULL, "
                       "tel VARCHAR(30) NOT NULL, "
                       "yuanix VARCHAR(50) NOT NULL, "
                       "zhuanye VARCHAR(30) NOT NULL, "
                       "qinshi VARCHAR(30) NOT NULL, "
                       "class VARCHAR(30) NOT NULL)");

    //创建数据库class表
    query.exec("CREATE TABLE class ("
                       "name VARCHAR(40) PRIMARY KEY NOT NULL, "
                       "department VARCHAR(50) NOT NULL, "
                       "instructor VARCHAR(40) NOT NULL, "
                       "instructor_number VARCHAR(40) NOT NULL,"
                        "people_number INTEGER NOT NULL)");

    Login l;
    l.setWindowTitle("LOGIN");
    l.show();
    //初始化创建一个管理员账户：admin admin
    Admin_admin *admin_admin=new Admin_admin;
    admin_admin->hide();
    return a.exec();
}
