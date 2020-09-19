#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QFile>
#include <QPainter>
#include <QtGui>
#include <QDialog>
#include <QToolBar>
#include <QTextFrame>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QMainWindow>
#include <QIcon>
#include <QPushButton>
#include <QPixmap>
#include <QTime>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
