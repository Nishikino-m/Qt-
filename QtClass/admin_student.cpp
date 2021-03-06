#include "admin_student.h"
#include "ui_admin_student.h"
#include "uandp.h"
#include "add_student.h"
#include "change_student.h"
Admin_Student::Admin_Student(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Admin_Student)
{
    ui->setupUi(this);
    this->setWindowTitle("Admin_student");
    QIcon icon;
    icon.addFile(":/new/prefix1/Image/Admin.png");

    QSqlDatabase db= QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("QtClass.db");
    if ( !db.open()){
           qDebug()<<"没有打开！";
       }
    QSqlQueryModel *model = new QSqlQueryModel(this);
    model->setQuery("select id,password,name,sex,yuanxi,zhuanye,phone_number,dormitory,className from student");
    //以下为展示的各列的名称
    model->setHeaderData(0,Qt::Horizontal,tr("学号"));
    model->setHeaderData(1,Qt::Horizontal,tr("密码"));
    model->setHeaderData(2,Qt::Horizontal,tr("姓名"));
    model->setHeaderData(3,Qt::Horizontal,tr("性别"));
    model->setHeaderData(4,Qt::Horizontal,tr("院系"));
    model->setHeaderData(5,Qt::Horizontal,tr("专业"));
    model->setHeaderData(6,Qt::Horizontal,tr("联系电话"));
    model->setHeaderData(7,Qt::Horizontal,tr("寝室号"));
    model->setHeaderData(8,Qt::Horizontal,tr("班级号"));
       ui->tableView->setModel(model);

}

Admin_Student::~Admin_Student()
{
    delete ui;
}

//增加学生信息
void Admin_Student::on_pushButton_clicked()
{
    add =new Add_Student;
    add ->setModal(true);
    add ->show();
    qDebug()<<"Add";
    this->close();
}

//修改学生信息
void Admin_Student::on_pushButton_2_clicked()
{
    changee =new change_student;
    changee ->setModal(true);
    changee ->show();

    qDebug()<<"Change";
    this->close();
}


//删除学生信息
void Admin_Student::on_pushButton_3_clicked()
{
    qDebug()<<"DEc";
    QString wantDeleteStuentId=ui->DeclineEdit->text();
    if(wantDeleteStuentId==""){QMessageBox::information(this, "警告", "您未输入想要删除的学生学号");return;};
    //判断输入想要删除的班级是否存在于数据库中
    QSqlQuery query;
    query.exec("select id from student");
    bool isExist=false;//是否存在
    while(query.next())
               {
                   QString tempStudentId=query.value(0).toString();
                   if(tempStudentId.compare(wantDeleteStuentId)==0){
                       QString sql=QString("delete from student where id='%1'").arg(wantDeleteStuentId);
                       query.exec(sql);
                        QMessageBox::information(this, "温馨提示", "恭喜，学号："+wantDeleteStuentId+"删除成功");
                       qDebug()<<wantDeleteStuentId+"删除成功";
                       isExist=false;
                       //自动刷新表格
                       this->close();
                       Admin_Student *newAdminStudentShow=new Admin_Student;
                       newAdminStudentShow->show();
                       break;
                   }
                   isExist=true;
              }
    if(isExist){
                  QMessageBox::information(this, "WARNING", "抱歉，不存在学号:"+wantDeleteStuentId);
                 qDebug()<<wantDeleteStuentId+"删除失败";
                 //this->close();
                 ui->DeclineEdit->setText("");
    }
}

//选中tableview，获取选中的内容
void Admin_Student::on_tableView_clicked(const QModelIndex &index)
{
    QString tableViewValue=index.data().toString();
    QClipboard *board=QApplication::clipboard();
       board->setText(tableViewValue);
       QMessageBox::information(this, "温馨提示", "信息"+tableViewValue+"已复制到粘贴板");
}
