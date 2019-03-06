#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Metody Modelowania Matematycznego - Projekt Lipkiewicz Okuniewska");
    //ui->transmitationWindow->

    createTextTransmitation();
    ui->transmitationWindow->setText(textTransmitation);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createTextTransmitation()
{
    textTransmitation.append("Postać transmitancji H(s) = \n b1s + b0  \n");
    textTransmitation.append("------------------- \n");
    textTransmitation.append("s^2 + " + QString::number(paramA1) + "s + ");
    textTransmitation.append(QString::number(paramA0));
}


