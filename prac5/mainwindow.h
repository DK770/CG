#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void bresenham(float,float,float,float);
    void floodFill(float,float,QRgb,QRgb); //x,y,fillcolor,bgcolor
    void drawChessBoard(float,int); //side length
    void fillChessBoard(float,int); //fill board
private:
    Ui::MainWindow *ui;
    //float stx = 250;
    //float sty = 70;
};

#endif // MAINWINDOW_H
