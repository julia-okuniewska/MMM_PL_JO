#ifndef MATEMATYKA_H
#define MATEMATYKA_H

#include <QtCharts>
#include <QLineSeries>
#include <cmath>



class Matematyka
{
public:
    Matematyka();

    // te funkcje są robocze, wymagają serduszka
    void wejscieProstokatne(QLineSeries *values);
    void wejscieHeavyside(QLineSeries *values);
    void wejscieSinus(QLineSeries *values);


    int rectangleInput (double i);
    int heavysideInput(double i);
    double sinusInput (double i);

    double transmitationFun(double i);
    double splotFun(double x);
    double simpsonIntegration ( double xlast);
    void fillsplot (double splot [2000] );
    double splot ( double i);
    //------------------------------------------

    QLineSeries *obliczaneDane;

    double minimumX = 0;
    double maksimumX = 10000;

    double minimumY = 20000;
    double maksimumY = -20000;
    const int numberOfPoints = 200;
    int Tin=10;

private:

    void checkMinimum(double value);
    void checkMaksimum(double value);

};

#endif // MATEMATYKA_H
