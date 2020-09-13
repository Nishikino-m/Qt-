#include "subhelpwidget.h"
#include <QMessageBox>
#include<QMenu>
#include <QPainter>
Subhelpwidget::Subhelpwidget(QWidget *parent) : QWidget(parent)
{
    setFixedSize(600,400);
    x.setParent(this);
    x.setText("OK");
    x.move(450,300);
    connect(&x,&QPushButton::clicked,this,&Subhelpwidget::close);

}
void Subhelpwidget::paintEvent(QPaintEvent *)
{

    QPainter painter(this);//（绘制对象）
    painter.setPen(QColor(200,0,0));//设置画笔颜色 RGB
  //  painter.setPen(QPen());
    painter.setBrush(QBrush(QColor(200,0,0)));//
    painter.drawLine(QPoint(50,50),QPoint(590,50));//绘制直线
    painter.drawLine(QPoint(590,50),QPoint(590,390));//绘制直线
    painter.drawLine(QPoint(590,390),QPoint(50,390));//绘制直线
    painter.drawLine(QPoint(50,390),QPoint(50,50));//绘制直线

}

