#include "gamewidget.h"

GameWidget::GameWidget(QWidget *parent) : QWidget(parent)
{
    setFixedSize(1200,720);
    this->setWindowTitle("Game");
    SetChooseButton();
//搞贴图或gif 四个人物形象  选择不同的人就进入不同的初始化界面
//搞成纯机器自己动？
//初始化 地图 所有玩家在起点
    connect(&ret, &QPushButton::released, this, &GameWidget::sendSlot);//返回开始界面


}

void GameWidget::SetChooseButton()
{
    b1.setParent(this);
    b1.setText("Choose");
    b1.move(100,600);
    ///
    b2.setParent(this);
    b2.setText("Choose");
    b2.move(400,600);
    ///
    b3.setParent(this);
    b3.setText("Choose");
    b3.move(700,600);
    ///
    b4.setParent(this);
    b4.setText("Choose");
    b4.move(1000,600);
    ///
    ret.setParent(this);
    ret.setText("<-");
    ret.move(50,50);
}
void GameWidget::sendSlot()//发送信号，使完成返回的效果
{
    emit mySignal();
}
