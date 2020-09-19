#ifndef ADMIN_STUDENT_H
#define ADMIN_STUDENT_H

#include <QDialog>
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
namespace Ui {
class Admin_Student;
}

class Admin_Student : public QDialog
{
    Q_OBJECT

public:
    explicit Admin_Student(QWidget *parent = 0);
    ~Admin_Student();
    studentTableShow();

private slots:
    void on_pushButton_clicked();//增加学生信息

    void on_pushButton_2_clicked();//修改学生信息

    void on_pushButton_3_clicked();//删除学生信息


    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::Admin_Student *ui;
   // admin_student_add *studentAdd;//创建增加学生信息对象
   // admin_student_updata *studentUpdate;//创建更新学生信息对象
};

#endif // ADMIN_STUDENT_H
