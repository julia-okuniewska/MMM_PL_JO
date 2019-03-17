#ifndef OLCHART_H
#define OLCHART_H

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QDebug>
#include <QtCharts>
#include <QChartView>
#include <QValueAxis>
#include <QLogValueAxis>

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

    QAbstractAxis *axisX;
    QAbstractAxis *axisY;

    void linLinAxis();
    void loglogAxis();

};

#endif // OLCHART_H
