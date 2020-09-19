#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setWindowIcon(QIcon("logo.ico"));//设置窗口图标
    setFixedSize(400,600);
    ui->setupUi(this);
    //制作菜单栏
    QMenuBar *mBar =menuBar();
    QMenu *pFile = mBar->addMenu("帮助");
    QAction *pNew= pFile->addAction("关于");

    connect(pNew,&QAction::triggered,
            [=]()
            {
              QMessageBox::about(this,"介绍","这是基于Qt5.9.2制作的学生管理系统\n\n制作者:林煊 李嘉琳 许瑶琪");
              qDebug()<<"关于 被按下了！";
            });
    pFile->addSeparator();//添加分割线


    //退出按钮
    connect(ui->safeexit,&QPushButton::released,this,&MainWindow::close);

}

MainWindow::~MainWindow()
{
    delete ui;
}
