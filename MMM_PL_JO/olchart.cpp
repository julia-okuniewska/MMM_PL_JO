#include "olchart.h"


olChart::olChart()
{
    blackPen.setColor(Qt::black);

   this->legend()->hide();
   przebieg = new QLineSeries();

    for (int i = 0 ;  i < 100 ; i ++)
    {
      przebieg->append(double(i), 0.5*i);
      qDebug()<<przebieg->at(i);
    }

   this->addSeries(przebieg);

    // wywala odwołanie do pustego
    this->setTitle("Charakterystyka Amplitudowa");
//    myChart->axes(Qt::Horizontal).first()->setRange(0, zakresX);
//    myChart->axes(Qt::Horizontal).first()->setRange(0, zakresY);


  // setRenderHint(QPainter::Antialiasing);


}

void olChart::prepareolChart()
{

}

olChart::~olChart()
{

}
