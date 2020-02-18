#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <bits/stdc++.h>

QImage image(500, 500, QImage::Format_RGB888);

QRgb fillcolor = qRgb(255,0,0);
QRgb bgcolor = qRgb(0,0,0);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

template<class T>
T sign(T x){
    if(!x)
        return 0;
    if(x>0)
        return 1;
    return -1;
}

void MainWindow::on_pushButton_clicked(){
    //Draw Chessboard
    float dim;
    int order;
    dim=ui->textEdit->toPlainText().toFloat();
    order=ui->textEdit_2->toPlainText().toInt();
    drawChessBoard(dim,order);
    ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::on_pushButton_2_clicked(){
    //Fill Chessboard
    //floodFill(x1,y1,qRgb(255,255,255),qRgb(0,0,0));
    float dim;
    int order;
    dim=ui->textEdit->toPlainText().toFloat();
    order=ui->textEdit_2->toPlainText().toInt();
    fillChessBoard(dim,order);
    ui->label->setPixmap(QPixmap::fromImage(image));
}

//if(!i || !(3-i))
void MainWindow::drawChessBoard(float dim,int order){
    float side = dim/sqrt(2);
    //float unitsq = side/4;
    float unitsq = side/order;
    float x=250,y=70;
    for(int i=0; i<order+1; i++){
        bresenham(x-(i*unitsq), y+(i*unitsq), x+((order-i)*unitsq), y+side+(i*unitsq));
        bresenham(x+(i*unitsq), y+(i*unitsq), x-((order-i)*unitsq), y+side+(i*unitsq));
    }
}

void MainWindow::fillChessBoard(float dim, int order){
    float x=250, y=70;
    float side = dim/sqrt(2);
    //float unitsq = side/4;
    float unitsq = side/order;
    /*
    for(int i=0; i<4; i++){
            floodFill(x,y+(unitsq*(2*i+1)),fillcolor,bgcolor);
            if(i==1 || i==2){
                floodFill(x+(2*unitsq),y+(unitsq*(2*i+1)),fillcolor,bgcolor);
                floodFill(x-(2*unitsq),y+(unitsq*(2*i+1)),fillcolor,bgcolor);
            }
    }
    */
    for(int i=0; i<order; i++){
        floodFill(x,y+(unitsq*(2*i+1)),fillcolor,bgcolor);
        int k = std::min(i,order-i-1);

        for(int j=1; j<=k; j++){
            //floodFill(x+(unitsq*(2*j+1)),y+(unitsq*(2*i+1)),fillcolor,bgcolor);
            //floodFill(x-(unitsq*(2*j+1)),y+(unitsq*(2*i+1)),fillcolor,bgcolor);
            floodFill(x+(unitsq*(2*j)),y+(unitsq*(2*i+1)),fillcolor,bgcolor);
            floodFill(x-(unitsq*(2*j)),y+(unitsq*(2*i+1)),fillcolor,bgcolor);
        }

    }
}

void MainWindow::floodFill(float x, float y, QRgb fillcolor, QRgb bgcolor){
    if(image.pixel(x,y) == bgcolor){
        image.setPixel(x,y,fillcolor);
        floodFill(x+1,y,fillcolor,bgcolor);
        floodFill(x,y+1,fillcolor,bgcolor);
        floodFill(x-1,y,fillcolor,bgcolor);
        floodFill(x,y-1,fillcolor,bgcolor);
    }
}

void MainWindow::bresenham(float x1, float y1, float x2, float y2)
{
    //QRgb value;
    //value=qRgb(255,255,255);
    float x=x1,y=y1;
    float delx = fabs(x2-x1);
    float dely = fabs(y2-y1);
    float dx = sign(x2-x1);
    float dy = sign(y2-y1);
    bool interchange;

    if(dely>delx){
        std::swap(delx,dely);
        interchange = 1;
    }
    else
        interchange = 0;

    float err = 2*(dely-delx);

    for(int i=0;i<=delx;i++){

       image.setPixel(x,y,fillcolor);

       while(err>0){
           if(interchange)
               x += dx;
           else
               y += dy;
           err -= 2*delx;
       }
       if(interchange)
           y += dy;
       else
           x += dx;

       err += 2*dely;
    }
}

