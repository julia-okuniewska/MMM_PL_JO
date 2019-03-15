#include "olchart.h"

olChart::olChart()
{

}

olChart::olChart(QGraphicsView *view)
{
    blackPen.setColor(Qt::black);
    this->view = view;
    scene = new QGraphicsScene(0,0,view->width(), view->height(),view);

    myChart = new QChart();
    myChart->legend()->hide();
    przebieg = new QLineSeries();

    for (int i = 0 ;  i < 100 ; i ++)
    {
      przebieg->append(double(i), 0.5*i);
      qDebug()<<przebieg->at(i);
    }

    myChart->addSeries(przebieg);

    // wywala odwołanie do pustego
    myChart->setTitle("Charakterystyka Amplitudowa");
//    myChart->axes(Qt::Horizontal).first()->setRange(0, zakresX);
//    myChart->axes(Qt::Horizontal).first()->setRange(0, zakresY);

    scene->addItem(myChart);

    this->view->setRenderHint(QPainter::Antialiasing);
    this->view->show();

}

void olChart::prepareolChart()
{

}

olChart::~olChart()
{
    delete scene;
}
