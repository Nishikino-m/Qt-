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
    QSqlDatabase database= QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("QtClass.db");
    if ( !database.open()){
           qDebug()<<"没有打开！";
       }
    QSqlQuery query;
  //创建数据库admin表
    QString createDB="CREATE TABLE admin (admin_account VARCHAR(40) PRIMARY KEY NOT NULL,admin_password VARCHAR(40) NOT NULL,admin_else VARCHAR(40) )";

    //创建数据库student表
    query.exec(createDB);

     query.exec("CREATE TABLE student ("
                    "id VARCHAR(50) PRIMARY KEY NOT NULL, "
                    "name VARCHAR(30) NOT NULL, "
                    "sex VARCHAR(10) NOT NULL, "
                    "yuanxi VARCHAR(50) NOT NULL,"
                    "zhuanye VARCHAR(50) NOT NULL,"
                    "phone_number VARCHAR(30) NOT NULL,"
                    "password VARCHAR(30) NOT NULL,"
                    "dormitory VARCHAR(30) NOT NULL,"
                    "className VARCHAR(30) NOT NULL)");

    //创建数据库teacher表
    query.exec("CREATE TABLE teacher ("
                       "id VARCHAR(40) PRIMARY KEY NOT NULL, "
                       "name VARCHAR(50) NOT NULL, "
                       "sex VARCHAR(10) NOT NULL, "
                       "yuanxi VARCHAR(50) NOT NULL,"
                "phone_number VARCHAR(30) NOT NULL,"
                       "password VARCHAR(30) NOT NULL,"
                       "subject VARCHAR(40) NOT NULL)");

    Login l;
    l.setWindowTitle("LOGIN");
    l.show();
    //初始化创建一个管理员账户：admin admin
    Admin_admin *admin_admin=new Admin_admin;
    admin_admin->hide();
    return a.exec();
}
