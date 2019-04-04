#include "matematyka.h"


Matematyka::Matematyka()
{

}

int Matematyka::rectangleInput(double i)
{        
        int gorka = 1;
        int dolinka= -1;
        int faza=int(i)%Tin;
        if(faza>Tin/2)
        {
            return gorka;
        }
        return dolinka;

}

double Matematyka::sinusInput (double i)
{
    return sin(Tin*i);
}

int Matematyka::heavysideInput(double i)
{
    if(i>0)
        return 1;
    return 0;
}


void Matematyka::wejscieProstokatne(QLineSeries *values)
{
    //  WYŁACZNIE PRZYKŁADOWE
    double obliczaneY;
    for (double i = -2; i < 1000; i += 2) {

        for(double j = 0 ; j <=2 ; j+=0.01){

            if (j == 0. || j == 1.) obliczaneY = 0.5;
            else if(j>0 && j <1) obliczaneY = 1;
            else obliczaneY = 0;

            values->append(i+j, obliczaneY);
        }
    }

    minimumY  = -1;
    maksimumY =  2;
    maksimumX = 10;
}

void Matematyka::wejscieHeavyside(QLineSeries *values)
{
    //  WYŁACZNIE PRZYKŁADOWE
    for (double i = -1 ; i< 500 ; i+=0.01) {

        if(i<0){
            values->append(i,0);
        }
        else{
            values->append(i,1);
        }
        minimumY = -2;
        maksimumY = 2;
    }

    minimumX = -1;
    maksimumX = 10;
}

void Matematyka::wejscieSinus(QLineSeries *values)
{
    //  WYŁACZNIE PRZYKŁADOWE
    for (double i = 0; i < 4 * M_PI; i += (M_PI_4/2)) {

        double calculated = sin(i);
        checkMinimum(calculated);
        checkMaksimum(calculated);
        values->append(i,calculated);
    }
}
double Matematyka::transmitationFun( double i)
{
    if(i==0.) return 0;
    double y= 1*i;
    return y;
}


double Matematyka:: splotFun(double x)
{
    //double z=transmitationFun(x);
    //double y=0;
    return rectangleInput(x)*transmitationFun(x);
//    for (double j=0; j<10; j=j+0.1){
//        y += z*rectangleInput(x+j);
//    }
//    return y;
    //return transmitationFun(x)*rectangleInput(x);

}

double Matematyka::simpsonIntegration (double xlast)
{
    double xfirst, y, sum, dx, x;
    xfirst=0;
    y=0;
    sum=0;
    dx=(xlast-xfirst)/numberOfPoints;
    for (int i=1; i<=numberOfPoints; i++)
    {
        x = xfirst + i*dx;
        sum += splotFun(x-dx/2);
        if (i< numberOfPoints)
        {
           y+= splotFun(x);
        }
    }
    y = dx/6 * (splotFun(xfirst)+splotFun(xlast) + 2*y + 4*sum);
    return y;
}


double Matematyka::splot (double i )
{

        return splotFun(i);
}


void Matematyka::checkMinimum(double value)
{
    if(value<minimumY)
    minimumY = value;
}

void Matematyka::checkMaksimum(double value)
{
    if(value>maksimumY)
    maksimumY = value;

}
