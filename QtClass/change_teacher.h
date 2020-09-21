#ifndef CHANGE_TEACHER_H
#define CHANGE_TEACHER_H

#include <QDialog>
#include "headers.h"

namespace Ui {
class change_teacher;
}

class change_teacher : public QDialog
{
    Q_OBJECT

public:
    explicit change_teacher(QWidget *parent = 0);
    ~change_teacher();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
private:
    Ui::change_teacher *ui;

};

#endif // CHANGE_TEACHER_H
