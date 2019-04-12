#ifndef MATEMATYKA_H
#define MATEMATYKA_H

#include <QtCharts>
#include <QLineSeries>
#include <cmath>
#include <QDebug>


class Matematyka
{
public:
    Matematyka();




    int rectangleInput (double i);
    int heavysideInput(double i);
    double sinusInput (double i);


    void transformataOdwrotna();

    double transmitationFun(double i);
    double splotFun(double x);
    double simpsonIntegration ( double xlast);

    double rectangle1 (double i, char wybrane_wejscie );
    double checkMaksimum();

    //------------------------------------------

    QLineSeries *obliczaneDane;

    double minimumX = 0;
    double maksimumX = 10000;

    double minimumY = 20000;
    double maksimumY = -20000;
    const static int numberOfPoints = 2000;
    double e = 2.72;         //liczba Eulera
    double pi = 3.1415;        //liczba PI
    int Tin=30;
    double max_time=100;
    double step=0.01;            //max_time/numberOfPoints;
    char typ_wejscia;

    double outputData[numberOfPoints];


private:

    void checkMinimum(double value);

};

#endif // MATEMATYKA_H
