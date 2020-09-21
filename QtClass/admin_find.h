#ifndef ADMIN_FIND_H
#define ADMIN_FIND_H

#include <QDialog>
#include "headers.h"

namespace Ui {
class Admin_find;
}

class Admin_find : public QDialog
{
    Q_OBJECT

public:
    explicit Admin_find(QWidget *parent = 0);
    ~Admin_find();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

private:
    Ui::Admin_find *ui;

};

#endif // ADMIN_FIND_H
