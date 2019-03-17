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
    }
}

void Matematyka::wejscieSinus(QLineSeries *values)
{
    values->append(1,1);
    values->append(100,100);
}
