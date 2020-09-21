#ifndef ADMIN_ADMIN_H
#define ADMIN_ADMIN_H

#include <QDialog>
#include "headers.h"
namespace Ui {
class Admin_admin;
}

class Admin_admin : public QDialog
{
    Q_OBJECT

public:
    explicit Admin_admin(QWidget *parent = 0);
    ~Admin_admin();
private slots:
    void on_add_clicked();//增加admin

    void on_sub_clicked();//删除admin

    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::Admin_admin *ui;
    adminTableShow();
};

#endif // ADMIN_ADMIN_H
