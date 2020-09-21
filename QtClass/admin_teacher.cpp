#include "admin_teacher.h"
#include "ui_admin_teacher.h"
#include "headers.h"
#include "change_teacher.h"
#include "add_teacher.h"
Admin_teacher::Admin_teacher(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Admin_teacher)
{
    ui->setupUi(this);
    this->setWindowTitle("Admin_teacher");
    QIcon icon;
    icon.addFile(":/new/prefix1/Image/Admin.png");

    QSqlDatabase db= QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("QtClass.db");
    if ( !db.open()){
           qDebug()<<"没有打开！";
       }
    QSqlQuery query;
    QSqlQueryModel *model = new QSqlQueryModel(this);
    model->setQuery("select id,password,name,sex,yuanxi,subject,phone_number from teacher");
    //以下为展示的各列的名称
    model->setHeaderData(0,Qt::Horizontal,tr("教工编号"));
    model->setHeaderData(1,Qt::Horizontal,tr("密码"));
    model->setHeaderData(2,Qt::Horizontal,tr("姓名"));
    model->setHeaderData(3,Qt::Horizontal,tr("性别"));
    model->setHeaderData(4,Qt::Horizontal,tr("院系"));
    model->setHeaderData(5,Qt::Horizontal,tr("授课科目"));
    model->setHeaderData(6,Qt::Horizontal,tr("联系电话"));
    ui->tableView->setModel(model);
}

Admin_teacher::~Admin_teacher()
{
    delete ui;
}
void Admin_teacher::on_pushButton_clicked()
{
    add =new add_teacher;
    add ->setModal(true);
    add ->show();
    qDebug()<<"Add";
    this->close();
}

//修改信息
void Admin_teacher::on_pushButton_2_clicked()
{
    changee =new change_teacher;
    changee ->setModal(true);
    changee ->show();

    qDebug()<<"Change";
    this->close();
}


//删除信息
void Admin_teacher::on_pushButton_3_clicked()
{
    qDebug()<<"DEc";
    QString wantDec=ui->lineEdit->text();
    if(wantDec==""){QMessageBox::information(this, "警告", "您未输入想要删除的教工编号");return;};
    QSqlQuery query;
    query.exec("select id from teacher");
    bool isExist=false;//是否存在
    while(query.next())
               {
                   QString tempStudentId=query.value(0).toString();
                   if(tempStudentId.compare(wantDec)==0){
                       QString sql=QString("delete from student where id='%1'").arg(wantDec);
                       query.exec(sql);
                        QMessageBox::information(this, "温馨提示", "恭喜，学号："+wantDec+"删除成功");
                       qDebug()<<wantDec+"删除成功";
                       isExist=false;
                       //自动刷新表格
                       this->close();
                       Admin_teacher *newAdminteacher=new Admin_teacher;
                       newAdminteacher->show();
                       break;
                   }
                   isExist=true;
              }
    if(isExist){
                  QMessageBox::information(this, "WARNING", "抱歉，不存在学号:"+wantDec);
                 qDebug()<<wantDec+"删除失败";
                 //this->close();
                 ui->lineEdit->setText("");
    }
}

//选中tableview，获取选中的内容
void Admin_teacher::on_tableView_clicked(const QModelIndex &index)
{
    QString tableViewValue=index.data().toString();
    QClipboard *board=QApplication::clipboard();
       board->setText(tableViewValue);
       QMessageBox::information(this, "温馨提示", "信息"+tableViewValue+"已复制到粘贴板");
}
