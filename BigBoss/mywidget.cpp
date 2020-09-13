#include "mywidget.h"
#include <QPainter>
#include <QIcon>
#include <QPushButton>
#include <QtGui>
#include <QTextFrame>
MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
     setFixedSize(1200,720);
     setWindowIcon(QIcon("logo.ico"));

     start.setParent(this);
     start.setText("START");
     start.move(500,360);
     exit.setParent(this);
     exit.setText("EXIT");
     exit.move(500,460);
     help.setParent(this);
     help.setText("HELP");
     help.move(1000,100);

     connect(&start,&QPushButton::released,this,&MyWidget::gamestart);//游戏开始的子窗口
     connect(&exit,&QPushButton::released,this,&MyWidget::close);//退出游戏
     connect(&help,&QPushButton::released,this,&MyWidget::helpmenu);//弹出帮助对话框
     connect(&w, &GameWidget::mySignal, this,&MyWidget::Hidegame);//接收信号，使子窗口隐藏，本窗口显示，造成返回的效果

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
void MyWidget::Hidegame()
{
    w.hide();
    this->show();
}
void MyWidget::helpmenu()
{
//    h.show();
      QMessageBox::about(NULL, "帮助", "          -游戏规则-\n①20回合后，按资产数目排行\n②走到空土地时，可以选择购买/不买这块地\n③走到他人已购买的土地时，根据土地情况支付给土地主人过路费\n④走到自己的土地（除车站）时，可选择支付一定的现金加盖房屋\n⑤走到“进牢”或抽出要求进牢的卡片时，直接位移到牢狱，此时\n路过起点无资金收入\n⑥现金不足时，玩家可选择抵押土地（房产)从银行获取房产半价的\n现金此时其他玩家不能购买这块土地，但经过时无需支付过路费\n⑦若总资产为非正数，玩家宣布破产，土地上的房屋全部拆除，变\n为无主状态");
}
