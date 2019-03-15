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

class olChart : public QChart
{
    Q_OBJECT
public:
    olChart();
    void prepareolChart();
    ~olChart();


private:

    QLineSeries *przebieg;    
    QPen blackPen;
};

#endif // OLCHART_H
