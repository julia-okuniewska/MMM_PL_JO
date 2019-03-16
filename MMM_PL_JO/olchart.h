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


typedef struct
{
    type_of_chart typeOfChart;
    QLineSeries *wejsciowy;

} dataOfChart;


class olChart : public QChart
{
    Q_OBJECT

public:

    olChart(type_of_chart typ_wykresu);
    void setSeries(QLineSeries *wej);
    void setAllRanges(int bottomX, int topX, int bottomY, int topY);

private:

    QValueAxis *axisX;
    QValueAxis *axisY; 

};

#endif // OLCHART_H
