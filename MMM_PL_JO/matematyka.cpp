#include "matematyka.h"

Matematyka::Matematyka()
{

}
void Matematyka::wejscieProstokatne(QLineSeries *values)
{
    values->append(1,1);
    values->append(100,100);
}

void Matematyka::wejscieHeavyside(QLineSeries *values)
{
    qDebug()<<"hedynka ";
    for (int i = -10 ; i< 100 ; i ++ ) {

        if(i<0){
            values->append(i,0);
        }
        else{
            values->append(i,1);
        }
        minimum = -2;
        maksimum = 2;
    }
}

void Matematyka::wejscieSinus(QLineSeries *values)
{
    qDebug()<<"sines";
    for (double i = 0; i < 2 * M_PI; i += M_PI_4) {

        double calculated = sin(i);
        checkMinimum(calculated);
        checkMaksimum(calculated);
        values->append(i,calculated);

    }
}

void Matematyka::checkMinimum(double value)
{
    if(value<minimum)
    minimum = value;
}

void Matematyka::checkMaksimum(double value)
{
    if(value>maksimum)
    maksimum = value;

}
