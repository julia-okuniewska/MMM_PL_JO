#include "olchart.h"

olChart::olChart()
{

}

olChart::olChart(QGraphicsView *view)
{
    blackPen.setColor(Qt::black);
    this->view = view;
    scene->addLine(5,5,100,100,blackPen);
    this->view->setScene(scene);
}
