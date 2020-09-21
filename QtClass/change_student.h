#ifndef CHANGE_STUDENT_H
#define CHANGE_STUDENT_H

#include "uandp.h"
#include "headers.h"
namespace Ui {
class change_student;
}

class change_student : public QDialog
{
    Q_OBJECT

public:
    explicit change_student(QWidget *parent = 0);
    ~change_student();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::change_student *ui;
};

#endif // CHANGE_STUDENT_H
