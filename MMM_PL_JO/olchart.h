#ifndef OLCHART_H
#define OLCHART_H

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QDebug>
#include <QtCharts>
#include <QChartView>
#include <QAbstractAxis>
#include <QValueAxis>
#include <QLogValueAxis>

#include "matematyka.h"


enum type_of_chart {WEJSCIE, WYJSCIE, AMPLITUDOWY, FAZOWY};

enum input_signal {SQUARE, HEAVYSIDE, SINUS};


class olChart : public QChart
{
    Q_OBJECT

public:

    olChart(type_of_chart typ_wykresu);

    void setAllRanges(int bottomX, int topX, double bottomY, double topY);

    void drawInput(input_signal pobudzenie);

    type_of_chart typeOfChart;
    QLineSeries *wejsciowy;



    QValueAxis *axisX;
    QValueAxis *axisY;
    QLogValueAxis *laxisX;
    QLogValueAxis *laxisY;
    Matematyka matematyka;
    void linLinAxis();
    void loglogAxis();


};

#endif // OLCHART_H
