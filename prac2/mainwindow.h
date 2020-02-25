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

public slots:
    void dda(float x1, float y1, float x2, float y2);
    void bresenham(float x1, float y1, float x2, float y2);
    void circle(float r, float x, float y);
    void mh(int &xi, int &deli);
    void md(int &xi, int &yi, int &deli);
    void mv(int &yi, int &deli);
    void bCircle(int r, int x, int y);
    void ddaCircle(float r, float x, float y);
    //template<class T>
    float sign(float x);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
