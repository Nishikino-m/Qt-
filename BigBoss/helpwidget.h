#ifndef HELPWIDGET_H
#define HELPWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "subhelpwidget.h"
class HelpWidget : public QWidget
{
    Q_OBJECT
public:
    explicit HelpWidget(QWidget *parent = nullptr);

    void show1();
    void show2();
    void show3();

signals:

public slots:

private:
    Subhelpwidget p1;
    Subhelpwidget p2;
    Subhelpwidget p3;
    QPushButton b1;
    QPushButton b2;
    QPushButton b3;

    QPushButton ok;

};

#endif // HELPWIDGET_H
