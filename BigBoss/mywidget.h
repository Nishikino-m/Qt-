#ifndef MYWIDGET_H
#define MYWIDGET_H

#include "gamewidget.h"
#include "helpwidget.h"
#include <QWidget>
#include <QPushButton>
class MyWidget : public QWidget
{
    Q_OBJECT
private:
    QPushButton start;
    QPushButton exit;
    QPushButton help;

    GameWidget w;
    HelpWidget h;
public:
    MyWidget(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void gamestart();
    void helpmenu();
    void Hidegame();
    ~MyWidget();
};

#endif // MYWIDGET_H
