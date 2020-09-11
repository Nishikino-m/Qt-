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
    Q_OBJECT
public:
    explicit GameWidget(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // GAMEWIDGET_H
