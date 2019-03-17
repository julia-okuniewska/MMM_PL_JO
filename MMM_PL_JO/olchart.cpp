#include "olchart.h"

olChart::olChart(type_of_chart typ_wykresu)
{
    this->legend()->hide();


    switch (typ_wykresu) {
    case WEJSCIE:

        linLinAxis();
        this->setTitle("Sygnał wejściowy");
        break;

    case WYJSCIE:

        linLinAxis();
        this->setTitle("Sygnał wyjściowy");
        break;

    case AMPLITUDOWY:

        loglogAxis();
        this->setTitle("Charakterystyka Amplitudowa");
        laxisY->setTitleText("Amplituda [dB]");
        laxisX->setTitleText("Częstotliwość [rad/s]");

        break;

    case FAZOWY:

        loglogAxis();
        this->setTitle("Charakterystyka Fazowa");
        laxisY->setTitleText("Faza [stopnie]");
        laxisX->setTitleText("Częstotliwość [rad/s]");

        break;
    }


    setAllRanges(-10,20,-10,10);
    wejsciowy = new QLineSeries();
    addSeries(wejsciowy);


}





void olChart::setAllRanges(int bottomX, int topX, double bottomY, double topY)
{
    //    PRZESZCZEP
    //    this->axes(Qt::Horizontal).first()->setRange(bottomX, topX);
    //    this->axes(Qt::Vertical).first()->setRange(bottomY, topY);

    axisX->setRange(bottomX,topX);
    axisY->setRange(bottomY,topY);

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
    laxisX->setBase(20);
    laxisY->setBase(20);

  //  this->addAxis(laxisX, Qt::AlignBottom);
    //this->addAxis(laxisY, Qt::AlignLeft);
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
        break;

    case HEAVYSIDE:
        matematyka.wejscieHeavyside(wejsciowy);
        break;
    case SINUS:
        matematyka.wejscieSinus(wejsciowy);
        setAllRanges(-10,10,matematyka.minimum, matematyka.maksimum);
        break;

    }
    addSeries(wejsciowy);
    wejsciowy->attachAxis(axisX);
    wejsciowy->attachAxis(axisY);
}
