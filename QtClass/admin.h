#ifndef ADMIN_H
#define ADMIN_H

#include <QDialog>
#include "admin_student.h"
#include "admin_admin.h"
#include "admin_find.h"
#include "admin_teacher.h"
namespace Ui {
class Admin;
}

class Admin : public QDialog
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = 0);
    ~Admin();

private:
    Ui::Admin *ui;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Admin_Student *studentTable;//展示student表
    Admin_admin *adminTable;//展示admin表
    Admin_teacher *teacherTable;//展示teacher表
    Admin_find *findTable;//查找
};

#endif // ADMIN_H
