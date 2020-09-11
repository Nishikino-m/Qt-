#include "subhelpwidget.h"

Subhelpwidget::Subhelpwidget(QWidget *parent) : QWidget(parent)
{
    setFixedSize(300,300);
    this->setWindowTitle("www");
    x.setParent(this);
    x.setText("XX");
    x.move(50,50);
}


