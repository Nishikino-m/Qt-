#ifndef ADMIN_FIND_H
#define ADMIN_FIND_H

#include <QDialog>

namespace Ui {
class Admin_find;
}

class Admin_find : public QDialog
{
    Q_OBJECT

public:
    explicit Admin_find(QWidget *parent = 0);
    ~Admin_find();

private:
    Ui::Admin_find *ui;
};

#endif // ADMIN_FIND_H
