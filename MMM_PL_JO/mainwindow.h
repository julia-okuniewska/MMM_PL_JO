#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include<QString>




namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int a_0 = 25;
    int a_1 = 5;
    int b_0 = 15;
    int b_1 = 35;
    int T   = 10;

  QString textTransmitation;

    void createTextTransmitation();
    void display_remarks();

private slots:
    void on_lineEdit_textChanged();

    void on_lineEdit_2_textChanged();

    void on_lineEdit_8_textChanged();

    void on_lineEdit_3_textChanged();

    void on_lineEdit_4_textChanged();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
