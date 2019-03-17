#include "olchart.h"

olChart::olChart(type_of_chart typ_wykresu)
{
    this->legend()->hide();


    switch (typ_wykresu) {
    case WEJSCIE:

        linLinAxis();
        this->setTitle("Sygnał wejściowy");
        axisY->setTitleText("wartość sygnału");
        axisX->setTitleText("czas [s]");

        break;

    case WYJSCIE:

        linLinAxis();
        this->setTitle("Sygnał wyjściowy");
        axisY->setTitleText("wartość sygnału");
        axisX->setTitleText("czas [s]");

        break;

    case AMPLITUDOWY:

        loglogAxis();
        this->setTitle("Charakterystyka Amplitudowa");
        axisY->setTitleText("Amplituda [dB]");
        axisX->setTitleText("Częstotliwość [rad/s]");

        break;

    case FAZOWY:

        loglogAxis();
        this->setTitle("Charakterystyka Fazowa");
        axisY->setTitleText("Faza [stopnie]");
        axisX->setTitleText("Częstotliwość [rad/s]");

        break;
    }

    this->addAxis(axisY, Qt::AlignLeft);
    this->addAxis(axisX, Qt::AlignBottom);

    setAllRanges(-10,20,-10,10);
    wejsciowy = new QLineSeries();
    addSeries(wejsciowy);
}





void olChart::setAllRanges(int bottomX, int topX, int bottomY, int topY)
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
}

void olChart::loglogAxis()
{
    axisX = new QLogValueAxis();
    axisY = new QLogValueAxis();
}
