#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Metody Modelowania Matematycznego - Projekt Lipkiewicz Okuniewska");
    ui->transmitationWindow->setReadOnly(true);


    prepareButtons();
    createTextTransmitation();


    olchart = new olChart(WEJSCIE);

    ui->graphicsView->setChart(olchart);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    olchartDolny = new olChart(AMPLITUDOWY);
    ui->graphicsView_2->setChart(olchartDolny);

    emit on_pushButton_clicked();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createTextTransmitation()
{
    ui->transmitationWindow->clear();
    textTransmitation.clear();


    textTransmitation.append("Postać transmitancji H(s)" );
//    int  id = signalsButton.checkedId();
//    if(id == -1 ) return;
//    textTransmitation.append( signalsButton.button(id)->text());

    textTransmitation.append("\n" + QString::number(b_1) + "s + " + QString::number(b_0) +"\n");
    textTransmitation.append("-------------------   * exp ( -s * "+QString::number(T));
    textTransmitation.append(")\n s^2 + " + QString::number(a_1) + "s + ");
    textTransmitation.append(QString::number(a_0));

    ui->transmitationWindow->setPlainText(textTransmitation);


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

void MainWindow::prepareButtons()
{
    ui->pushButton->setCheckable(true);
    ui->pushButton_2->setCheckable(true);
    ui->pushButton_3->setCheckable(true);
    signalsButton.addButton(ui->pushButton);
    signalsButton.addButton(ui->pushButton_2);
    signalsButton.addButton(ui->pushButton_3);

    signalsButton.setExclusive(true);
    ui->pushButton->setChecked(true);

}

void MainWindow::on_lineEdit_textChanged()
{
    QString a_1_string = ui->lineEdit->text();
    bool convertOK;
    a_1 = a_1_string.toInt(&convertOK);
    display_remarks();
    createTextTransmitation();

}

void MainWindow::on_lineEdit_2_textChanged()
{
    QString a_0_string = ui->lineEdit_2->text();
    bool convertOK;
    a_0 = a_0_string.toInt(&convertOK);
    display_remarks();
    createTextTransmitation();

}

void MainWindow::on_lineEdit_8_textChanged()
{
    QString b_1_string = ui->lineEdit_8->text();
    bool convertOK;
    b_1 = b_1_string.toInt(&convertOK);
    display_remarks();
    createTextTransmitation();
}


void MainWindow::on_lineEdit_3_textChanged()
{
    QString b_0_string = ui->lineEdit_3->text();
    bool convertOK;
    b_0 = b_0_string.toInt(&convertOK);
    display_remarks();
    createTextTransmitation();
}

void MainWindow::on_lineEdit_4_textChanged()
{
    QString T_string = ui->lineEdit_4->text();
    bool convertOK;
    T = T_string.toInt(&convertOK);
    display_remarks();
    createTextTransmitation();
}


void MainWindow::on_pushButton_clicked()
{
    olchart->drawInput(SQUARE);
    createTextTransmitation();
}

void MainWindow::on_pushButton_2_clicked()
{
    olchart->drawInput(HEAVYSIDE);
    createTextTransmitation();
}

void MainWindow::on_pushButton_3_clicked()
{
    olchart->drawInput(SINUS);
    createTextTransmitation();
}
