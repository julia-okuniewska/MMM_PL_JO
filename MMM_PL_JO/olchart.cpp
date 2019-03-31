#include "olchart.h"

olChart::olChart(type_of_chart typ_wykresu)
{
    this->legend()->hide();
    daneNaWykresie = new QLineSeries();

    addSeries(daneNaWykresie);


    switch (typ_wykresu) {
    case WEJSCIE:

        linLinAxis();
        this->setTitle("Sygnał wejściowy");
        ustawPrzedzialyWykresu(WEJSCIE, -10,20,-10,10);
        break;

    case WYJSCIE:

        linLinAxis();
        this->setTitle("Sygnał wyjściowy");
        ustawPrzedzialyWykresu(WYJSCIE, -10,10,-10,110);
        break;

    case AMPLITUDOWY:

        loglogAxis();
        this->setTitle("Charakterystyka Amplitudowa");
        laxisY->setTitleText("Amplituda [dB]");
        laxisX->setTitleText("Częstotliwość [rad/s]");
        ustawPrzedzialyWykresu(AMPLITUDOWY, -10,200,-10,100);

        break;

    case FAZOWY:

        loglogAxis();
        this->setTitle("Charakterystyka Fazowa");
        laxisY->setTitleText("Faza [stopnie]");
        laxisX->setTitleText("Częstotliwość [rad/s]");
        ustawPrzedzialyWykresu(FAZOWY, -10,30,-10,10);

        break;
    }

}

void olChart::setData(type_of_chart typ_wykresu, QLineSeries *danePrzekazane)
{
    removeSeries(daneNaWykresie);
    daneNaWykresie = danePrzekazane;
    this->addSeries(daneNaWykresie);

    if(typ_wykresu == WEJSCIE || typ_wykresu == WYJSCIE){

       daneNaWykresie->attachAxis(axisX);
       daneNaWykresie->attachAxis(axisY);
    }
    else {
        daneNaWykresie->attachAxis(laxisX);
        daneNaWykresie->attachAxis(laxisY);
    }
}

void olChart::ustawPrzedzialyWykresu(type_of_chart typ_wykresu, double bottomX, double topX, double bottomY, double topY)
{
    if(typ_wykresu == WEJSCIE || typ_wykresu == WYJSCIE){
        axisX->setRange(bottomX,topX);
        axisY->setRange(bottomY,topY);

    }
    else {
        laxisX->setRange(bottomX,topX);
        laxisY->setRange(bottomY,topY);
    }
}

void olChart::linLinAxis()
{
    axisX = new QValueAxis();
    axisY = new QValueAxis();

    axisY->setTitleText("wartość sygnału");
    axisX->setTitleText("czas [s]");

    this->addAxis(axisX, Qt::AlignBottom);
    this->addAxis(axisY, Qt::AlignLeft);
}

void olChart::loglogAxis()
{

    laxisX = new QLogValueAxis();
    laxisY = new QLogValueAxis();

    laxisX->setLabelFormat("%g");
    laxisY->setLabelFormat("%g");

    laxisX->setBase(10.0);
    laxisY->setBase(10.0);

    laxisX->setMinorTickCount(5);
    laxisY->setMinorTickCount(5);

    this->addAxis(laxisX, Qt::AlignBottom);
    this->addAxis(laxisY, Qt::AlignLeft);
}
