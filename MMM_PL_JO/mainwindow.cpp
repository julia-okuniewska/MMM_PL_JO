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

void MainWindow::display_remarks()
{

    QString mistake="bledne wspolczynniki:";
    if(a_0==0)
    {
        mistake += " a0";
    }
    if(a_1==0)
    {
        mistake += " a1";
    }
    if(b_0==0)
    {
        mistake += " b0";
    }
    if(b_1==0)
    {
        mistake += " b1";
    }
    if(T==0)
    {
        mistake += " T";
    }
    ui->remarks->setText(mistake);

    if(a_0 != 0 && a_1 != 0 && b_0 != 0 && b_1 != 0 && T!=0)
        ui->remarks->setText(" ");
}

void MainWindow::on_lineEdit_textChanged()
{
    QString a_1_string = ui->lineEdit->text();
    bool convertOK;
    a_1 = a_1_string.toInt(&convertOK);
    display_remarks();

}

void MainWindow::on_lineEdit_2_textChanged()
{
    QString a_0_string = ui->lineEdit_2->text();
    bool convertOK;
    a_0 = a_0_string.toInt(&convertOK);
    display_remarks();

}

void MainWindow::on_lineEdit_8_textChanged()
{
    QString b_1_string = ui->lineEdit_8->text();
    bool convertOK;
    b_1 = b_1_string.toInt(&convertOK);
    display_remarks();
}


void MainWindow::on_lineEdit_3_textChanged()
{
    QString b_0_string = ui->lineEdit_3->text();
    bool convertOK;
    b_0 = b_0_string.toInt(&convertOK);
    display_remarks();
}

void MainWindow::on_lineEdit_4_textChanged()
{
    QString T_string = ui->lineEdit_4->text();
    bool convertOK;
    T = T_string.toInt(&convertOK);
    display_remarks();
}
