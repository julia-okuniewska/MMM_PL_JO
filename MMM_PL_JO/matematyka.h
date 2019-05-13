#ifndef MATEMATYKA_H
#define MATEMATYKA_H

#include <QtCharts>
#include <QLineSeries>
#include <cmath>
#include <QDebug>
#include <complex>
#include <QVector>

#define AMPLITUDE 20
#define PHASE 45




class Matematyka
{
public:
    Matematyka();



    int rectangleInput (double i);
    int heavysideInput(double i);
    double sinusInput (double i);


    void transformataOdwrotna();

    std::complex<double> transmitationFun(double omega);

    double simpsonIntegration ( double xlast);
    double rectangle1 (double t, char wybrane_wejscie );
    double checkMaksimum();
    double checkMinimum();
    QString notacja_wykladniczaMaks();
    QString notacja_wykladniczaMin();

    QString Smaksimum;
    QString Sminimum;

    void amplitudeSpectrum();
    void phaseSpectrum();
    void spectrumMaxMin(int type, double value);

    void MatrixMultiplication (double Matrix1[2][2], double Matrix2[2][2], double outMatrix[2][2]);
    void MatrixAdd(double Matrix1[2][2], double Matrix2[2][2], double outMatrix[2][2]);
    void MatrixTransposition (double inMatrix1[2][2], double outMatrix[2][2]);
    void MatrixInverse (double inMatrix[2][2], double outMatrix[2][2]);
    void MatrixConstMult(double inMatrix[2][2], double mnoznik, double outMatrix[2][2]);
    void wypelnijMacierzDX (double t);

    void wypelnij_macierze();
    
    void calkowanie ();
    double wyliczanie_wyjscia (double t);

    //------------------------------------------

    QLineSeries *obliczaneDane;


    const static int numberOfPoints = 10000;
    const double e = 2.72;         //liczba Eulera
    const double pi = 3.1415;        //liczba PI
   int Tin=30;
    double max_time=100;
    double step=max_time/numberOfPoints;
            //max_time/numberOfPoints;            //max_time/numberOfPoints;
    char typ_wejscia;
    double outputData[numberOfPoints];
    
    double dx;

    double MatrixX[2][2];       //[2][1]
    double MatrixA[2][2];
    double MatrixB[2][2];       //[2][1]
    double MatrixC[2][2];       //[1][2]
    double dxMatrix[2][2];      //[1][2]
    double outputMatrix[2][2];   // tylko jeden element (błagam nie pytaj dlaczego XDDDDDDDDDD NIE UMIEM INACZEJ )

    double inverseMatrixA[2][2];

    double TemporaryMatrix0[2][2];
    double TemporaryMatrix1[2][2];

    double a_0=10;
    double a_1=10;
    double b_0=10;
    double b_1=10;
    double T = 0;

    double minimumRange = 1000;
    double maksimumRange = -1000;



private:


};

#endif // MATEMATYKA_H
