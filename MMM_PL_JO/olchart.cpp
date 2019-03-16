#include "olchart.h"

olChart::olChart(type_of_chart typ_wykresu)
{
    this->legend()->hide();
    axisX = new QValueAxis();
    axisY = new QValueAxis();


    switch (typ_wykresu) {
    case WEJSCIE:

        this->setTitle("Sygnał wejściowy");
        axisY->setTitleText("wartość sygnału");
        axisX->setTitleText("czas [s]");

        break;

    case WYJSCIE:

        this->setTitle("Sygnał wyjściowy");
        axisY->setTitleText("wartość sygnału");
        axisX->setTitleText("czas [s]");

        break;

    case AMPLITUDOWY:

        this->setTitle("Charakterystyka Amplitudowa");
        axisY->setTitleText("Amplituda [dB]");
        axisX->setTitleText("Częstotliwość [rad/s]");

        break;

    case FAZOWY:

        this->setTitle("Charakterystyka Fazowa");
        axisY->setTitleText("Faza [stopnie]");
        axisX->setTitleText("Częstotliwość [rad/s]");

        break;
    }

    this->addAxis(axisY, Qt::AlignLeft);
    this->addAxis(axisX, Qt::AlignBottom);

    setAllRanges(-10,10,-2,2);
}


void olChart::setAllRanges(int bottomX, int topX, int bottomY, int topY)
{
    //    PRZESZCZEP
    //    this->axes(Qt::Horizontal).first()->setRange(bottomX, topX);
    //    this->axes(Qt::Vertical).first()->setRange(bottomY, topY);

    axisX->setRange(bottomX,topX);
    axisY->setRange(bottomY,topY);

}
