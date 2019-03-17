#ifndef OLCHART_H
#define OLCHART_H

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QDebug>
#include <QtCharts>
#include <QChartView>
#include <QValueAxis>


enum type_of_chart {WEJSCIE, WYJSCIE, AMPLITUDOWY, FAZOWY};




class olChart : public QChart
{
    Q_OBJECT

public:

    olChart(type_of_chart typ_wykresu);

    void setAllRanges(int bottomX, int topX, int bottomY, int topY);


    type_of_chart typeOfChart;
    QLineSeries *wejsciowy;

private:

    QValueAxis *axisX;
    QValueAxis *axisY; 

};

#endif // OLCHART_H
