#include "helpwidget.h"
#include <QMessageBox>
#include <QMenu>
#include <QLabel>
HelpWidget::HelpWidget(QWidget *parent) : QWidget(parent)
{
    setFixedSize(800,500);
    this->setWindowTitle("Help");
    SetButton();
    SetSubw();
    QLabel txt;
    txt.setText("帮助");
    connect(&ok,&QPushButton::released,this,&HelpWidget::close);
    connect(&b1,&QPushButton::released,this,&HelpWidget::show1);
    connect(&b2,&QPushButton::released,this,&HelpWidget::show2);
    connect(&b3,&QPushButton::released,this,&HelpWidget::show3);
}

void HelpWidget::show1()
{
    //p1.show();
    p1.setVisible(true);
    p2.setVisible(false);
   // p2.hide();
   // p3.hide();
    p3.setVisible(false);
}

void HelpWidget::show2()
{
   // p2.show();
    p2.setVisible(true);
    //p1.hide();
    p1.setVisible(false);
    //p3.hide();
    p3.setVisible(false);
}

void HelpWidget::show3()
{
    //p3.show();
    p3.setVisible(true);
   // p2.hide();
   // p1.hide();
    p1.setVisible(false);
    p2.setVisible(false);

}
void HelpWidget::SetButton()
{
    b1.setParent(this);
    b1.setText("1");
    b1.move(150,400);
    ///
    b2.setParent(this);
    b2.setText("2");
    b2.move(350,400);
    ///
    b3.setParent(this);
    b3.setText("3");
    b3.move(550,400);
    ///
    ok.setParent(this);
    ok.setText("OK");
    ok.move(800,450);
    ///
}
void HelpWidget::SetSubw()
{
    p1.move(75,0);
    p2.move(75,0);
    p3.move(75,0);
    p1.setParent(this);
    //设置为不可见
    p1.setVisible(false);
    p2.setVisible(false);
    p3.setVisible(false);
    p2.setParent(this);
    p3.setParent(this);
}
