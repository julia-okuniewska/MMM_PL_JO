#ifndef OLCHART_H
#define OLCHART_H

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QDebug>
#include <QtCharts>
#include <QChartView>
#include <QValueAxis>

#define zakresX 50
#define zakresY 150

enum type_of_chart {WEJSCIE, WYJSCIE, AMPLITUDOWY, FAZOWY};
enum input_signal {SQUARE, HEAVYSIDE, SINUS};

typedef struct
{
    type_of_chart typeOfChart;
    input_signal inputOfChart;

} chartData;

typedef struct{
    QLineSeries *wejsciowy;
    QLineSeries *wyjsciowy;
}przebieg;


class olChart : public QChart
{
    Q_OBJECT
public:

    olChart(type_of_chart typ_wykresu, input_signal sygnal_wejscia);
    ~olChart();

    void setAllRanges(int bottomX, int topX, int bottomY, int topY);



private:

    QValueAxis *axisX;
    QValueAxis *axisY; 

};

#endif // OLCHART_H
