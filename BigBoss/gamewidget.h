#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QPushButton>
class GameWidget : public QWidget
{
private:
    QPushButton b1;
    QPushButton b2;
    QPushButton b3;
    QPushButton b4;
    QPushButton ret;
    Q_OBJECT
public:
    explicit GameWidget(QWidget *parent = nullptr);
    void SetChooseButton();
    void ReturnMain();
    void sendSlot();
signals:
    void mySignal();
public slots:
};

#endif // GAMEWIDGET_H
