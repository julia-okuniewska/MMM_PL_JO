#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <QString>
#include <QButtonGroup>
#include <QDebug>

#include "olchart.h"

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
    int T   = startPoint

  QString textTransmitation;
  QString nameOfFunctions[3] = {"fala prostokątna",
                                "skok jednostkowy",
                                "sinusoida"};

    void createTextTransmitation();
    void display_remarks();
    void prepareButtons();


private slots:
    void on_lineEdit_textChanged();

    void on_lineEdit_2_textChanged();

    void on_lineEdit_8_textChanged();

    void on_lineEdit_3_textChanged();

    void on_lineEdit_4_textChanged();

    void on_pushButton_clicked();




    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    QButtonGroup signalsButton;
    olChart *olchart;
};

#endif // MAINWINDOW_H
