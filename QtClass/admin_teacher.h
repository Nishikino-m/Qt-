#ifndef ADMIN_TEACHER_H
#define ADMIN_TEACHER_H

#include <QDialog>

namespace Ui {
class Admin_teacher;
}

class Admin_teacher : public QDialog
{
    Q_OBJECT

public:
    explicit Admin_teacher(QWidget *parent = 0);
    ~Admin_teacher();

private:
    Ui::Admin_teacher *ui;
};

#endif // ADMIN_TEACHER_H
