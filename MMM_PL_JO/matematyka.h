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

    double minimumY = 20000;
    double maksimumY = -20000;

    double minimumX = 0;
    double maksimumX = 10000;



private:

    void checkMinimum(double value);
    void checkMaksimum(double value);






};

#endif // MATEMATYKA_H
