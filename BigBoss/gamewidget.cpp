#include "gamewidget.h"

GameWidget::GameWidget(QWidget *parent) : QWidget(parent)
{
    setFixedSize(1200,720);
    this->setWindowTitle("Game");
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


}

