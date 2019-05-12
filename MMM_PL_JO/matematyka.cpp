#include "matematyka.h"


Matematyka::Matematyka()
{
wypelnij_macierze();

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
    if(i==0.)
    return 0;
}


double Matematyka::rectangle1 (double t, char wybrane_wejscie)
{
    if(wybrane_wejscie=='r')
    {
        return rectangleInput(t);                                                      //pow (pow(e, -1*i*Tin/2) - 1 , 2)/ (i*(1- pow(e, -1*i*Tin)));
    }

    if(wybrane_wejscie=='h')
    {
        return heavysideInput(t);
    }
    if(wybrane_wejscie=='s')
    {
        return sinusInput(t);
    }
    return 1;
}


double Matematyka::simpsonIntegration (double xlast)
{
    double xfirst, y, sum, dx, x;
    xfirst=0;
    y=0;
    sum=0;
    int N=200;
    dx=(xlast-xfirst)/N;
    for (int i=1; i<=N; i++)
    {
        x = xfirst + i*dx;
       // sum += splotFun(x-dx/2);
        if (i< N)
        {
          // y += splotFun(x);
        }
    }
   // y = dx/6 * (splotFun(xfirst)+splotFun(xlast) + 2*y + 4*sum);

    return y;
}


std::complex<double> Matematyka::transmitationFun(double omega)
{
    std::complex<double> licznik;
    std::complex<double> mianownik;
    std::complex<double> j(0,1);
    std::complex<double> expo(e,0);
    licznik = b_1*j*omega + b_0;
    mianownik = j*j*omega*omega + a_1*j*omega+a_0;


   return (licznik/mianownik)*pow(e,(-j*omega*T));

}


double Matematyka::checkMaksimum()
{
    double maksimumY=0;
    for (int i=0; i<numberOfPoints; i++)
    {
        if(outputData[i]>maksimumY)
        {
            maksimumY=outputData[i];
        }
    }
    return maksimumY;
}

double Matematyka::checkMinimum()
{
    double minimum=0;
    for (int i=0; i<numberOfPoints; i++)
    {
        if(outputData[i]<minimum)
        {
            minimum=outputData[i];
        }
    }
    return minimum;
}

void Matematyka::amplitudeSpectrum()
{
    maksimumRange = -10000;
    minimumRange = 10000;
    obliczaneDane = new QLineSeries();
       std::complex<double> yValue;
       double amplitude;
       for(double omega = 0.1; omega < 10000 ; omega *= 10){
           for(double i = 1; i <10 ; i++){
               yValue = transmitationFun(omega*i);
               amplitude = 20*log(abs(yValue));
               obliczaneDane->append(omega*i,amplitude);
               spectrumMaxMin(AMPLITUDE, amplitude);
           }
       }
}

void Matematyka::phaseSpectrum()
{
    maksimumRange = -10000;
    minimumRange = 10000;
    obliczaneDane = new QLineSeries();

    int vecIterator = 0;
    double odejmowane = 0;
    bool przeskok = 0;

    std::complex<double> yValue;
    double argument;
    for(double omega = 0.1; omega < 10000 ; omega *= 10){
        for(double i = 1; i <10 ; i++)
        {
             yValue = transmitationFun(omega*i);
             argument = (atan2(yValue.imag(),yValue.real())*180)/M_PI;

             if(vecIterator != 0)
             {
                 if( (argument * obliczaneDane->at(vecIterator - 1).y()) < 0)
                 {
                     if(przeskok == 0){
                         odejmowane += (2 * 180);
                         przeskok = 1;
                     }
                 }
                 else
                 {
                     przeskok = 0;
                 }


             }
             qDebug()<<"argument przed "<<argument;
             argument = argument - odejmowane;
             obliczaneDane->append(omega*i,argument);
             qDebug()<<"odejmowane = "<<odejmowane;

             //tak, są
            //   qDebug()<<"czy obliczane dane = "<<obliczaneDane->at(vecIterator)<<"sa rowne "<<unfolding->at(vecIterator);

             qDebug()<<"dla omega = "<<omega*i<<"argument = "<< argument<<endl;
             spectrumMaxMin(PHASE,argument);
             vecIterator++;
        }
    }
    qDebug()<<endl<<endl<<endl;
}

void Matematyka::spectrumMaxMin(int type, double value)
{
    if(value < minimumRange){
        minimumRange = value;
    }
    if(value > maksimumRange){
        maksimumRange = value;
        maksimumRange = (floor((maksimumRange/type))+1)*type;

        if(maksimumRange<=0){
            switch(type){
            case AMPLITUDE:
                maksimumRange = 20;
                break;
            case PHASE:
                maksimumRange = 45;
                break;
            }
        }
    }

    if (minimumRange<0)
        minimumRange = (floor((minimumRange/type)))*type;
    else
        minimumRange = (floor((minimumRange/type))+1)*type;

}



void Matematyka::wypelnij_macierze ()
{
    MatrixA[0][0]=0;
    MatrixA[0][1]=1;
    MatrixA[1][0]=-1*a_0;
    MatrixA[1][1]=-1*a_1;

    MatrixB[0][0]=MatrixB[1][1]=MatrixB[0][1]=0;
    MatrixB[1][0]=1;

    MatrixC[0][0]=b_0;
    MatrixC[0][1]=b_1;
    MatrixC[1][1]=MatrixC[1][0]=0;

    MatrixX[0][0]=MatrixX[0][1]=MatrixX[1][1]=MatrixX[1][0]=0;

}


void Matematyka:: MatrixMultiplication(double (*Matrix1)[2], double(*Matrix2)[2] , double (*outMatrix)[2])
{

    double s;
    for (int i=0; i<2; i++)
    {
        for (int j=0; j<2; j++){
            s=0;
            for(int k=0; k<2; k++)
            {
                s += Matrix1[i][k] * Matrix2[k][j];
                outMatrix[i][j]=s;
            }
        }
    }
}

void Matematyka:: MatrixAdd (double (*Matrix1)[2], double(*Matrix2)[2] , double (*outMatrix)[2])
{
    for (int i=0; i<2; i++)
    {
        for (int j=0; j<2; j++)
        {
            outMatrix[i][j]=Matrix1[i][j]+Matrix2[i][j];
        }
    }
}

void Matematyka::MatrixConstMult(double (*inMatrix)[2], double mnoznik, double (*outMatrix)[2])
{
    {
        for (int i=0; i<2; i++)
        {
            for (int j=0; j<2; j++)
            {
                outMatrix[i][j]=mnoznik * inMatrix[i][j];
            }
        }
    }
}

void Matematyka:: MatrixTransposition (double (*inMatrix)[2],  double (*outMatrix)[2])
{

    outMatrix[0][1]=inMatrix[1][0];
    outMatrix[1][0]=inMatrix[0][1];
    outMatrix[1][1]=inMatrix[1][1];
    outMatrix[0][0]=inMatrix[0][0];
}

void Matematyka::MatrixInverse (double (*inMatrix)[2],  double (*outMatrix)[2])
{
    double det = inMatrix[0][0]*inMatrix[1][1]-inMatrix[0][1]*inMatrix[1][0];
    outMatrix[0][0]=1/det*inMatrix[1][1];
    outMatrix[1][1]=1/det*inMatrix[0][0];
    outMatrix[0][1]=-1/det*inMatrix[0][1];
    outMatrix[1][0]=-1/det*inMatrix[1][0];

}

void Matematyka::transformataOdwrotna()
{
    for(int i=0; i<numberOfPoints; i++){
        outputData[i]=wyliczanie_wyjscia(i);
        //qDebug()<<outputData[i];
    }
}


double Matematyka::wyliczanie_wyjscia (double t)
{
    double wyjscie;
    wypelnijMacierzDX(t);
    calkowanie();
    MatrixMultiplication(MatrixC, MatrixX, outputMatrix);
    wyjscie=outputMatrix[0][0];
    return wyjscie;
}

void Matematyka::wypelnijMacierzDX(double t)
{
    MatrixMultiplication(MatrixA, MatrixX, TemporaryMatrix0);
    MatrixConstMult(MatrixB, rectangle1(t, typ_wejscia), TemporaryMatrix1);
    MatrixAdd(TemporaryMatrix0, TemporaryMatrix1, dxMatrix);
}


void Matematyka::calkowanie()
{
    MatrixConstMult(dxMatrix, step, TemporaryMatrix0);
    MatrixAdd(TemporaryMatrix0, MatrixX, MatrixX);
}




