#ifndef ADD_TEACHER_H
#define ADD_TEACHER_H

#include <QDialog>
#include "headers.h"
namespace Ui {
class add_teacher;
}

class add_teacher : public QDialog
{
    Q_OBJECT

public:
    explicit add_teacher(QWidget *parent = 0);
    ~add_teacher();

private:
    Ui::add_teacher *ui;
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
};

#endif // ADD_TEACHER_H
