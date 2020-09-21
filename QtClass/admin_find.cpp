#include "admin_find.h"
#include "ui_admin_find.h"
Admin_find::Admin_find(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Admin_find)
{
    ui->setupUi(this);
    this->setWindowTitle("Admin_find");
    QIcon icon;
    icon.addFile(":/new/prefix1/Image/Admin.png");
    QImage* img = new QImage;
        img->load(QString(":/new/prefix1/Image/find.jpg"));
        QImage scaledimg;
        scaledimg = img->scaled(ui->llabel->width(),ui->llabel->height(),Qt::KeepAspectRatio);
        ui->llabel->setPixmap(QPixmap::fromImage(scaledimg));
    QSqlDatabase db= QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("QtClass.db");
    if ( !db.open()){
           qDebug()<<"没有打开！";
       }
}

Admin_find::~Admin_find()
{
    delete ui;
}
//按学号查询
//多表查询: select table1.abc from table1 inner join table2 on table1.xxx=table2.xxx;
void Admin_find::on_pushButton_clicked()
{

    QString findId= ui->findidlineEdit->text().trimmed();


    QSqlQuery query1;

    QString sqlById=QString("select id,name,sex,yuanxi,zhuanye,phone_number,dormitory,className from student where id='%1'").arg(findId);
    query1.exec(sqlById);
    bool Notfond=true;
    while (query1.next()) {
       QString id=query1.value(0).toString();
       QString name=query1.value(1).toString();
       QString sex=query1.value(2).toString();
       QString yuanxi=query1.value(3).toString();
       QString zhuanye=query1.value(4).toString();
       QString phoneNumber=query1.value(5).toString();
       QString dormitory=query1.value(6).toString();
       QString className=query1.value(7).toString();
    //下面为查到的信息
       ui->idlineEdit->setText(id);
       ui->namelineEdit->setText(name);
       ui->sexlineEdit->setText(sex);
       ui->yuanxilineEdit->setText(yuanxi);
       ui->zhuanyelineEdit->setText(zhuanye);
       ui->tellineEdit->setText(phoneNumber);
       ui->qinshilineEdit->setText(dormitory);
       ui->classlineEdit->setText(className);
       Notfond=false;
    }
    if(Notfond){
       QMessageBox::information(this, "WARNING", "未找到相关信息");
       this->close();
       Admin_find *adminFind=new Admin_find;
       adminFind->show();
    }

}
//按姓名查找
void Admin_find::on_pushButton_2_clicked()
{
    QString findName=ui->findnamelineEdit->text().trimmed();
    QSqlQuery query2;
    QString sqlByName=QString("select id,name,sex,yuanxi,zhuanye,phone_number,dormitory,className from student where name='%1'").arg(findName);
    query2.exec(sqlByName);
    bool Notfond=true;
    while (query2.next()) {
       QString id=query2.value(0).toString();
       QString name=query2.value(1).toString();
       QString sex=query2.value(2).toString();
       QString yuanxi=query2.value(3).toString();
       QString zhuanye=query2.value(4).toString();
       QString phoneNumber=query2.value(5).toString();
       QString dormitory=query2.value(6).toString();
       QString className=query2.value(7).toString();
    //下面为查到的信息
       ui->idlineEdit->setText(id);
       ui->namelineEdit->setText(name);
       ui->sexlineEdit->setText(sex);
       ui->yuanxilineEdit->setText(yuanxi);
       ui->zhuanyelineEdit->setText(zhuanye);
       ui->tellineEdit->setText(phoneNumber);
       ui->qinshilineEdit->setText(dormitory);
       ui->classlineEdit->setText(className);
       Notfond=false;
    }
    if(Notfond){
       QMessageBox::information(this, "WARNING", "未找到相关信息");
       this->close();
       Admin_find *adminFind=new Admin_find;
       adminFind->show();
    }

}
//确认==退出
void Admin_find::on_pushButton_3_clicked()
{
    qDebug()<<"exit find";
    this->close();
}
