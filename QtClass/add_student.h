#ifndef ADD_STUDENT_H
#define ADD_STUDENT_H

#include "headers.h"
namespace Ui {
class Add_Student;
}

class Add_Student : public QDialog
{
    Q_OBJECT

public:
    explicit Add_Student(QWidget *parent = 0);
    ~Add_Student();

private:
    Ui::Add_Student *ui;
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
};

#endif // ADD_STUDENT_H
