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

    int paramA1 = 10;
    int paramA0 = 10;
    int paramT  = 5;

  QString textTransmitation;

    void createTextTransmitation();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
