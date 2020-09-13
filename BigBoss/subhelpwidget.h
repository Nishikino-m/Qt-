#ifndef SUBHELPWIDGET_H
#define SUBHELPWIDGET_H
#include <QPainter>
#include <QWidget>
#include <QPushButton>
class Subhelpwidget : public QWidget
{
    Q_OBJECT
private:
    QPushButton x;
public:
    explicit Subhelpwidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);

signals:

public slots:
};

#endif // SUBHELPWIDGET_H
