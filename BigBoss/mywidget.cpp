#include "mywidget.h"
#include <QPainter>
#include <QIcon>
#include <QPushButton>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
     setFixedSize(1200,720);
     setWindowIcon(QIcon("logo.ico"));
//
     start.setParent(this);
     start.setText("START");
     start.move(500,360);
     exit.setParent(this);
     exit.setText("EXIT");
     exit.move(500,460);
     help.setParent(this);
     help.setText("HELP");
     help.move(1000,100);

     connect(&start,&QPushButton::released,this,&MyWidget::gamestart);
     connect(&exit,&QPushButton::released,this,&MyWidget::close);
     connect(&help,&QPushButton::released,this,&MyWidget::helpmenu);
}

MyWidget::~MyWidget()
{

}
void MyWidget::paintEvent(QPaintEvent *)
{

    QPainter painter(this);//（绘制对象）
    painter.setPen(QColor(200,0,0));//设置画笔颜色 RGB
    painter.setBrush(QBrush(QColor(200,0,0)));//
    painter.drawLine(QPoint(10,10),QPoint(300,10));//绘制直线

}
void MyWidget::gamestart()
{
    w.show();
    this->hide();
}

void MyWidget::helpmenu()
{
    h.show();

}
