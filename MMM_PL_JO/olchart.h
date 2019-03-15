#ifndef OLCHART_H
#define OLCHART_H

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QDebug>
#include <QtCharts>
#include <QChartView>

#define zakresX 100
#define zakresY 50

class olChart : QObject
{
    Q_OBJECT
public:
    olChart();
    olChart(QGraphicsView *view);
    void prepareolChart();
    ~olChart();

     QChart *myChart;
private:

    QLineSeries *przebieg;
    QGraphicsView *view;
    QGraphicsScene *scene;
    QPen blackPen;
};

#endif // OLCHART_H
