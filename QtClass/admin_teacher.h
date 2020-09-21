#ifndef ADMIN_TEACHER_H
#define ADMIN_TEACHER_H

#include "headers.h"
#include "change_teacher.h"
#include "add_teacher.h"
namespace Ui {
class Admin_teacher;
}

class Admin_teacher : public QDialog
{
    Q_OBJECT

public:
    explicit Admin_teacher(QWidget *parent = 0);
    ~Admin_teacher();
private slots:
    void on_pushButton_clicked();//增加信息

    void on_pushButton_2_clicked();//修改信息
    void on_pushButton_3_clicked();//删除信息


    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::Admin_teacher *ui;
    change_teacher *changee;
    add_teacher *add;
};

#endif // ADMIN_TEACHER_H
