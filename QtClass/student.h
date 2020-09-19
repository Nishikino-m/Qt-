#ifndef STUDENT_H
#define STUDENT_H

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
class Student;
}

class Student : public QDialog
{
    Q_OBJECT

public:
    explicit Student(QWidget *parent = 0);
    ~Student();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Student *ui;
};

#endif // STUDENT_H
