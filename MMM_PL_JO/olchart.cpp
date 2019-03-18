#include "olchart.h"

olChart::olChart(type_of_chart typ_wykresu)
{
    this->legend()->hide();
    wejsciowy = new QLineSeries();

    switch (typ_wykresu) {
    case WEJSCIE:

        linLinAxis();
        this->setTitle("Sygnał wejściowy");
        setAllRanges(WEJSCIE, -10,20,-10,10);
        addSeries(wejsciowy);
        break;

    case WYJSCIE:

        linLinAxis();
        this->setTitle("Sygnał wyjściowy");
        setAllRanges(WYJSCIE, -10,20,-10,10);
        break;

    case AMPLITUDOWY:
        qDebug()<<"halo konstrutor";

        loglogAxis();
        this->setTitle("Charakterystyka Amplitudowa");
        laxisY->setTitleText("Amplituda [dB]");
        laxisX->setTitleText("Częstotliwość [rad/s]");
        setAllRanges(AMPLITUDOWY, -10,200,-10,100);


        break;

    case FAZOWY:

        loglogAxis();
        this->setTitle("Charakterystyka Fazowa");
        laxisY->setTitleText("Faza [stopnie]");
        laxisX->setTitleText("Częstotliwość [rad/s]");
        setAllRanges(FAZOWY, -10,20,-10,10);

        break;
    }



}

void olChart::setAllRanges(type_of_chart rodzaj, double bottomX, double topX, double bottomY, double topY)
{
    //    PRZESZCZEP
    //    this->axes(Qt::Horizontal).first()->setRange(bottomX, topX);
    //    this->axes(Qt::Vertical).first()->setRange(bottomY, topY);

    if(rodzaj == WEJSCIE || rodzaj == WYJSCIE){
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


    laxisX->setMinorTickCount(-1);
    laxisY->setMinorTickCount(-1);

addSeries(wejsciowy);

    *wejsciowy << QPointF(1.0, 1.0) << QPointF(2.0, 73.0) << QPointF(3.0, 268.0) << QPointF(4.0, 17.0)
              << QPointF(5.0, 4325.0) << QPointF(6.0, 723.0);


    this->addAxis(laxisX, Qt::AlignBottom);
    this->addAxis(laxisY, Qt::AlignLeft);

wejsciowy->attachAxis(laxisX);
wejsciowy->attachAxis(laxisY);
}


void olChart::drawInput(input_signal pobudzenie)
{
    if(wejsciowy->count() != 0) {
        removeSeries(wejsciowy);
        wejsciowy->clear();
    }
    else{
        qDebug()<<"Zbiór punktów jest pusty!";
        removeSeries(wejsciowy);
    }

    switch (pobudzenie) {

    case SQUARE:
         matematyka.wejscieProstokatne(wejsciowy);
         setAllRanges(WEJSCIE,0,5,-0.5,1.5);
        break;

    case HEAVYSIDE:
        matematyka.wejscieHeavyside(wejsciowy);
        setAllRanges(WEJSCIE,-2,5,-1,3);
        break;
    case SINUS:
        matematyka.wejscieSinus(wejsciowy);
        setAllRanges(WEJSCIE,0,4*M_PI,matematyka.minimum, matematyka.maksimum);
        break;

    }
    addSeries(wejsciowy);
    wejsciowy->attachAxis(axisX);
    wejsciowy->attachAxis(axisY);
}
