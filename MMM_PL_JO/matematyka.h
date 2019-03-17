#ifndef MATEMATYKA_H
#define MATEMATYKA_H

#include <QtCharts>
#include <QLineSeries>

class Matematyka
{
public:
    Matematyka();
    void wejscieProstokatne(QLineSeries *values);
    void wejscieHeavyside(QLineSeries *values);
    void wejscieSinus(QLineSeries *values);





};

#endif // MATEMATYKA_H
