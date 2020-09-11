#ifndef SUBHELPWIDGET_H
#define SUBHELPWIDGET_H

#include <QWidget>
#include <QPushButton>
class Subhelpwidget : public QWidget
{
    Q_OBJECT
private:
    QPushButton x;
public:
    explicit Subhelpwidget(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // SUBHELPWIDGET_H
