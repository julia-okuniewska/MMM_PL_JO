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
    ui->a1->setText("10");
    ui->b1->setText("10");
    ui->a0->setText("10");
    ui->b0->setText("10");
    ui->lineEdit_4->setText("0");
    ui->lineEdit_6->setText("30");
    ui->maximum_time->setText("100");
    display_stability();


}

MainWindow::~MainWindow()
{
    sent_data();
    delete ui;
}

void MainWindow::createTextTransmitation()
{

    ui->transmitationWindow->clear();
    textTransmitation.clear();


    textTransmitation.append("Postać transmitancji H(s)" );

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
    if(T==0.0)
    {
        mistake += " T";
    }
    ui->remarks->setText(mistake);

    if(a_0 != 0 && a_1 != 0 && b_0 != 0 && b_1 != 0 && T!=0.0)


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

    ui->pushButton_4->setCheckable(true);
    ui->pushButton_5->setCheckable(true);
    ui->pushButton_6->setCheckable(true);

    outputButton.addButton(ui->pushButton_4);
    outputButton.addButton(ui->pushButton_5);
    outputButton.addButton(ui->pushButton_6);


    signalsButton.setExclusive(true);
    outputButton.setExclusive(true);

    ui->pushButton->setChecked(true);

}

void MainWindow::on_a1_textChanged()
{
    QString a_1_string = ui->a1->text();
    bool convertOK;
    a_1 = a_1_string.toInt(&convertOK);
    display_remarks();
    display_stability();
    createTextTransmitation();
    matematyka.a_1= this->a_1;
    display_stability();

}

void MainWindow::on_a0_textChanged()
{
    QString a_0_string = ui->a0->text();
    bool convertOK;
    a_0 = a_0_string.toInt(&convertOK);
    display_remarks();
    display_stability();
    createTextTransmitation();
    matematyka.a_0 = this->a_0;

}

void MainWindow::on_b1_textChanged()
{
    QString b_1_string = ui->b1->text();
    bool convertOK;
    b_1 = b_1_string.toInt(&convertOK);
    display_remarks();
    createTextTransmitation();
    matematyka.b_1 = this->b_1;
    display_stability();
}


void MainWindow::on_b0_textChanged()
{
    QString b_0_string = ui->b0->text();
    bool convertOK;
    b_0 = b_0_string.toInt(&convertOK);
    display_remarks();
    createTextTransmitation();
    matematyka.b_0 = this->b_0;
    display_stability();

}

void MainWindow::on_lineEdit_4_textChanged()
{
    QString T_string = ui->lineEdit_4->text();
    bool convertOK;
    T = T_string.toDouble(&convertOK);
    display_remarks();
    createTextTransmitation();
    matematyka.T = this->T;
}


void MainWindow::on_pushButton_clicked()
{
    matematyka.typ_wejscia = 'r';               //INPUT RECTANGLE
    QLineSeries *dane =new QLineSeries();
    matematyka.wypelnij_macierze();
    double xfirst = -1*max_time/100;
    dane->append(xfirst, 0);
    dane->append(0, 0);
    for (int i=0; i<matematyka.numberOfPoints; i++)
    {
        double j=i*matematyka.step;
        dane->append(j, matematyka.rectangle1(j,'r'));
    }

    olchart->setData(WEJSCIE,dane);
    olchart->ustawPrzedzialyWykresu(WEJSCIE,xfirst,max_time,-1.5, 1.5);


}

void MainWindow::on_pushButton_2_clicked()      //INPUT HEAVYSIDE
{
    matematyka.typ_wejscia = 'h';
    QLineSeries *dane =new QLineSeries();
    matematyka.wypelnij_macierze();
    double xfirst = -1*max_time/100;
    dane->append(xfirst, 0);
    dane->append(0, 0);
    for (int i=0; i<matematyka.numberOfPoints; i++)
    {
       // double j=i/max_time;
        double j=i*matematyka.step;
        dane->append(j, matematyka.rectangle1(j,'h'));
    }
    olchart->setData(WEJSCIE,dane);
    olchart->ustawPrzedzialyWykresu(WEJSCIE,xfirst,max_time,-1.5, 1.5);

}

void MainWindow::on_pushButton_3_clicked()
{
    matematyka.typ_wejscia = 's';           //INPUD SINUS
    QLineSeries *dane =new QLineSeries();
    matematyka.wypelnij_macierze();
    double xfirst = -1*max_time/100;
    dane->append(xfirst, 0);
    dane->append(0, 0);
    for (int i=0; i<matematyka.numberOfPoints; i++)
    {
        double j=i*matematyka.step;
        dane->append(j, matematyka.rectangle1(j,'s'));
    }

    olchart->setData(WEJSCIE,dane);
    olchart->ustawPrzedzialyWykresu(WEJSCIE,xfirst,max_time,-1.5, 1.5);


}

void MainWindow::on_pushButton_4_clicked()
{

    matematyka.wypelnij_macierze();         //OUTPUT
    matematyka.transformataOdwrotna();

   // qDebug()<<"maksy = "<<maksimumY;

    olchartDolny = new olChart(WYJSCIE);
    QLineSeries *nowe =new QLineSeries();
    double xfirst = -1*max_time/100;
    nowe->append(xfirst, 0);
    nowe->append(T, 0);
    for (int i=0; i< matematyka.numberOfPoints; i++)       // to samo dla numberOfPoints i max_time...  DOŚĆ ZASTANAWIAJĄCE
    {
        double j= i*matematyka.step+T;
        nowe->append(j, matematyka.outputData[i]);

    }
    maksimum = matematyka.checkMaksimum()*1.1;
    minimum = matematyka.checkMinimum()*1.1;

    olchartDolny->setData(WYJSCIE,nowe);
    olchartDolny->ustawPrzedzialyWykresu( WYJSCIE, xfirst, max_time,minimum, maksimum );
    ui->graphicsView_2->setChart(olchartDolny);
    //qDebug()<<matematyka.outputData[0]<<matematyka.outputData[1]<<matematyka.outputData[2];

}

void MainWindow::on_pushButton_5_clicked()
{
    olchartDolny = new olChart(AMPLITUDOWY);
    QLineSeries *nowe = new QLineSeries();


    matematyka.amplitudeSpectrum();
    nowe = matematyka.obliczaneDane;

    olchartDolny->setData(AMPLITUDOWY,nowe);
    olchartDolny->ustawPrzedzialyWykresu(AMPLITUDOWY,0.1,10000,matematyka.minimumRange,matematyka.maksimumRange);

    int range = int(((abs(matematyka.maksimumRange)+abs(matematyka.minimumRange)))/20);
    olchartDolny->axisY->setTickCount(range+1);

    ui->graphicsView_2->setChart(olchartDolny);

}

void MainWindow::on_pushButton_6_clicked()
{
    olchartDolny = new olChart(FAZOWY);    
    QLineSeries *nowe = new QLineSeries();

    matematyka.phaseSpectrum();
    nowe = matematyka.obliczaneDane;

    olchartDolny->setData(FAZOWY,nowe);

    olchartDolny->ustawPrzedzialyWykresu(FAZOWY,0.1,10000,matematyka.minimumRange,matematyka.maksimumRange);

    if(matematyka.minimumRange>720)
    {
    int range = int(((abs(matematyka.maksimumRange)+abs(matematyka.minimumRange)))/40);
    olchartDolny->axisY->setTickCount(range+1);
    }
    else {
        olchartDolny->axisY->setTickCount(2);
    }
    ui->graphicsView_2->setChart(olchartDolny);    
}


void MainWindow::on_lineEdit_6_cursorPositionChanged()
{
    QString Tin_string = ui->lineEdit_6->text();
    bool convertOK;
    Tin = Tin_string.toInt(&convertOK);
    matematyka.Tin=Tin;

    
}
void MainWindow::sent_data()
{
    //matematyka.T=T;

    matematyka.Tin=this->Tin;
    olchartDolny->ustawPrzedzialyWykresu( WYJSCIE, -1*max_time/100, max_time, -1/maksimumY, maksimumY*1.05);
    matematyka.a_0=this->a_0;
    matematyka.a_1=this->a_1;
    matematyka.b_0=this->b_0;
    matematyka.b_1=this->b_1;
    matematyka.max_time=this->max_time;
}

bool MainWindow::check_stability(){

    if(a_0>=0 && a_1>=0)
        return true;
    return false;


}

void MainWindow::display_stability()
{
    czy_granica();
    QString stabilnosc;
    if(check_stability() && !czy_na_granicy)
    {
        stabilnosc="tak";
    }
    if(check_stability() && czy_na_granicy)
    {
        stabilnosc="na granicy";
    }
    if(!check_stability())
    {
        stabilnosc="nie";
    }

    ui->stability->setText("         ");
    ui->stability->setText(stabilnosc);

}


void MainWindow::on_maximum_time_textChanged()
{
    QString max_time_string = ui->maximum_time->text();
    bool convertOK;
    max_time= max_time_string.toInt(&convertOK);
    matematyka.max_time=this->max_time;
}

void MainWindow ::czy_granica()
{
    if(a_0==0 && a_1==0 && (b_0==0 || b_1==0))
    {
        czy_na_granicy=true;
    }
    else {
        czy_na_granicy=false;
    }
}


