#ifndef ADMIN_STUDENT_H
#define ADMIN_STUDENT_H


#include "add_student.h"
#include "change_student.h"
#include "headers.h"
namespace Ui {
class Admin_Student;
}

class Admin_Student : public QDialog
{
    Q_OBJECT

public:
    explicit Admin_Student(QWidget *parent = 0);
    ~Admin_Student();

private slots:
    void on_pushButton_clicked();//增加学生信息

    void on_pushButton_2_clicked();//修改学生信息

    void on_pushButton_3_clicked();//删除学生信息


    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::Admin_Student *ui;
    Add_Student *add;//创建增加学生信息对象
    change_student *changee;
};

#endif // ADMIN_STUDENT_H
