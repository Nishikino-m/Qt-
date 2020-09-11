#include "helpwidget.h"

HelpWidget::HelpWidget(QWidget *parent) : QWidget(parent)
{
    setFixedSize(1000,500);
    this->setWindowTitle("Help");
    b1.setParent(this);
    b1.setText("1");
    b1.move(200,400);
    ///
    b2.setParent(this);
    b2.setText("2");
    b2.move(400,400);
    ///
    b3.setParent(this);
    b3.setText("3");
    b3.move(600,400);
    ///
    ok.setParent(this);
    ok.setText("OK");
    ok.move(800,450);
    ///
    p1.setParent(this);
    p2.setParent(this);
    p3.setParent(this);
    connect(&ok,&QPushButton::released,this,&HelpWidget::close);
    connect(&b1,&QPushButton::released,this,&HelpWidget::show1);
    connect(&b2,&QPushButton::released,this,&HelpWidget::show2);
    connect(&b3,&QPushButton::released,this,&HelpWidget::show3);
}

void HelpWidget::show1()
{
    p1.show();
    p2.hide();
    p3.hide();
}

void HelpWidget::show2()
{
    p2.show();
    p1.hide();
    p3.hide();
}

void HelpWidget::show3()
{
    p3.show();
    p2.hide();
    p1.hide();

}


