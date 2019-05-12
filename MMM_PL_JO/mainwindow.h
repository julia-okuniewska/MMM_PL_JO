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


  QString textTransmitation;

    void createTextTransmitation();
    void display_remarks();
    void prepareButtons();
    void sent_data();


private slots:
    void on_lineEdit_textChanged();

    void on_lineEdit_2_textChanged();

    void on_lineEdit_8_textChanged();

    void on_lineEdit_3_textChanged();

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
