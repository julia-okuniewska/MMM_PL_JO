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


enum type_of_chart {WEJSCIE, WYJSCIE, AMPLITUDOWY, FAZOWY};
enum input_signal {SQUARE, HEAVYSIDE, SINUS};



class olChart : public QChart
{
    Q_OBJECT

public:


    olChart(type_of_chart typ_wykresu);

    void setData(type_of_chart typ_wykresu, QLineSeries *danePrzekazane);

    void ustawPrzedzialyWykresu(type_of_chart typ_wykresu , double bottomX, double topX, double bottomY, double topY);
    void ustawPrzedzialyWykresu2(type_of_chart typ_wykresu , double bottomX, double topX, QString bottomY, QString topY);




    type_of_chart typeOfChart;
    QLineSeries *daneNaWykresie;

    QValueAxis *axisX;
    QValueAxis *axisY;
    QLogValueAxis *laxisX;
    QLogValueAxis *laxisY;

    private:

    void linLinAxis();
    void loglogAxis();
    void loglinAxis();
};

#endif // OLCHART_H
