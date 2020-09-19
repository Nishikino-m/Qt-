#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include "admin.h"
#include "student.h"
namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();
    void login();
private slots:
    void on_login_clicked();
    void on_exit_clicked();
    void on_about_clicked();
private:
    Ui::Login *ui;
    Admin *admin;//创建管理员界面对象
    Student *student;//创建学生界面对象
};

#endif // LOGIN_H

