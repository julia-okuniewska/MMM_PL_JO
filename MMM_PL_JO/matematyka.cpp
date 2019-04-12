#include "matematyka.h"


Matematyka::Matematyka()
{


checkMaksimum();

}

int Matematyka:: rectangleInput(double x)
{
    int faza= int(x)%Tin;
    if(faza<Tin/2)
    {
        return 1;
    }
    return -1;
}



double Matematyka::sinusInput (double i)
{
    return sin(2*pi*i/Tin);
}

int Matematyka::heavysideInput(double i)
{
    if(i>0)
        return 1;
    return 0;
}



double Matematyka::rectangle1 (double i, char wybrane_wejscie)
{
    if(wybrane_wejscie=='r')
        return pow (pow(e, -1*step*i*Tin/2) - 1 , 2)/ (step*i*(1- pow(e, -1*i*step*Tin)));
    if(wybrane_wejscie=='h')
        return 1/(i*step);
    if(wybrane_wejscie=='s')
    {
        double w=2*pi/Tin;
        return w/(i*step*i*step+w*w);
    }
    return 1;
}


double Matematyka::transmitationFun( double i)
{
    if(i==0.) return 0;
    double y=1/(i);
    return y;
}


double Matematyka:: splotFun(double x)
{
    if(x==0.) return 0;
    return transmitationFun(x*step)*rectangle1(x*step, typ_wejscia);
}


double Matematyka::simpsonIntegration (double xlast)
{
    double xfirst, y, sum, dx, x;
    xfirst=0;
    y=0;
    sum=0;
    int N=20;
    dx=(xlast-xfirst)/N;
    for (int i=1; i<=N; i++)
    {
        x = xfirst + i*dx;
        sum += splotFun(x-dx/2);
        if (i< N)
        {
           y = y+ splotFun(x);
        }
    }
    y = dx/6 * (splotFun(xfirst)+splotFun(xlast) + 2*y + 4*sum);

    return y;
}


void Matematyka::transformataOdwrotna()
{
    for(int i=0; i<numberOfPoints; i++){
        outputData[i]=1/(2*3.14)*simpsonIntegration(i);
    }
}


void Matematyka::checkMinimum(double value)
{
    if(value<minimumY)
    minimumY = value;
}

double Matematyka::checkMaksimum()
{
    maksimumY=0;
    for (int i=0; i<numberOfPoints; i++){
        if(outputData[i]>maksimumY){
            maksimumY=outputData[i];
        }
    }
    return maksimumY;
}


