#ifndef OLCHART_H
#define OLCHART_H

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>


class olChart
{
public:
    olChart();
    olChart(QGraphicsView *view);


private:
    QGraphicsView *view;
    QGraphicsScene *scene;
    QPen blackPen;
};

#endif // OLCHART_H
