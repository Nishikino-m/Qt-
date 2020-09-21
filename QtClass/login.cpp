#include "login.h"
#include "ui_login.h"
#include "uandp.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
        ui->setupUi(this);
        setWindowIcon(QIcon("logo.ico"));
        //隐藏按钮边框
        ui->login->setStyleSheet("border:none;");
        ui->exit->setStyleSheet("border:none;");
        ui->about->setStyleSheet("border:none;");
        //设置图片
        ui->User->setPixmap(QPixmap(":/new/prefix1/Image/User.png"));
        ui->Passw->setPixmap(QPixmap(":/new/prefix1/Image/Clock.png"));
        QIcon icon;
        icon.addFile(":/new/prefix1/Image/Login.png");
        ui->login->setIcon(icon);
        ui->exit->setIcon(QPixmap(":/new/prefix1/Image/Exit.png"));
        ui->about->setIcon(QPixmap(":/new/prefix1/Image/About.png"));
        ui->Username->setPlaceholderText(tr("请输入用户名"));
        ui->Password->setPlaceholderText("请输入密码");
        ui->Password->setEchoMode(QLineEdit::Password);
        ui->label->setPixmap(QPixmap(":/new/prefix1/Image/Back.jpg"));
         ui->label->setScaledContents(true);
}

Login::~Login()
{
    delete ui;
}

//点击登录
void Login::on_login_clicked()
{
    //trimmed()去前后空格
    //tr()函数，防止设置中文时乱码
    QString username = ui->Username->text().trimmed();
    QString password = ui->Password->text();
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");//指定SQLite
    db.setDatabaseName("QtClass.db");//数据库
    if (!db.open())
            qDebug() << "连接失败";
    //管理员
    if( ui->AdminRadio->isChecked()){
        QSqlQuery query(db);
        db.exec("SET NAMES 'GBK'");//防止乱码
        query.exec("select admin_account,admin_password from admin");
        bool T1=false;
        while(query.next())
                   {
                       QString user = query.value(0).toString();
                       QString pass = query.value(1).toString();
                       if(username.compare(user)==0&&password.compare(pass)==0){
                           T1=true;
                           Login_Username=user;//记录登录者的账号
                           this->hide();
                           admin=new Admin;
                           admin->show();
                       }
                  }
        if(T1==false){
            QMessageBox::warning(this, tr("Warning"),tr("用户名或密码错误"),QMessageBox::Yes);

            //清空输入框内容
          //ui->Username->clear(); 保留输入的账号？
            ui->Password->clear();

            //光标定位
            ui->Password->setFocus();
        }

 }

    else if(ui->StudentRadio->isChecked()){
        QSqlQuery query(db);
        db.exec("SET NAMES 'GBK'");//防止乱码
        query.exec("select id,password from student");
        bool T2=false;
        while(query.next())
               {
                   QString user = query.value(0).toString();
                   QString pass = query.value(1).toString();
                   if(username.compare(user)==0&&password.compare(pass)==0){
                       T2=true;
                       Login_Username=user;//记录学生的账号
                       Login_Password=pass;//记录学生的密码
                       //this->hide();
                       this->close();
                       student=new Student;
                       //设置成模态对话框
                       student->setModal(true);
                       student->show();
                       break;
                   }
               }

    if(T2==false){
        QMessageBox::warning(this, tr("Warning"),tr("用户名或密码错误"),QMessageBox::Yes);

        //清空输入框内容
      //ui->Username->clear(); 保留输入的账号？
        ui->Password->clear();

        //光标定位
        ui->Password->setFocus();
    }


    }
    else{
        QMessageBox::warning(this, tr("Warning"),tr("请选择身份"),QMessageBox::Yes);
    }

}
void Login::on_exit_clicked()
{
    qDebug()<<"EXIT";
    this->close();
}
void Login::on_about_clicked()
{
    QMessageBox::information(this,"介绍","这是基于Qt5.9.2制作的学生管理系统\n\n制作者:林煊 李嘉琳 许瑶琪");
}
