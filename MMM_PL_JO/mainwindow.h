#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <QString>
#include <QButtonGroup>
#include <QDebug>


#include "olchart.h"
#include "matematyka.h"

#define startPoint 10;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int a_0 = startPoint
    int a_1 = startPoint
    int b_0 = startPoint
    int b_1 = startPoint
    double T   = 0;
    int Tin = 10;
    double max_time = 100;
    double maksimumY=2;
    bool czy_na_granicy = false;


  QString textTransmitation;

    void createTextTransmitation();
    void display_remarks();
    void prepareButtons();
    void sent_data();
    bool check_stability();
    void display_stability();


private slots:
    void on_a1_textChanged();

    void on_a0_textChanged();

    void on_b1_textChanged();

    void on_b0_textChanged();

    void on_lineEdit_4_textChanged();



    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();


    void on_lineEdit_6_cursorPositionChanged();

private:
    Ui::MainWindow *ui;
    QButtonGroup signalsButton;
    QButtonGroup outputButton;
    olChart *olchart;
    olChart *olchartDolny;
    Matematyka matematyka;
};

#endif // MAINWINDOW_H
