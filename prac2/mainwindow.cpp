#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<cmath>

QImage image(300,300, QImage::Format_RGB888);
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

//template<class T>
float MainWindow:: sign(float x){
    if(!x)
        return 0;
    if(x>0)
        return 1;
    return -1;
}

void MainWindow::dda(float x1, float y1, float x2, float y2)
{
    QRgb value;
    value=qRgb(000,255,000);
    float dx = x2-x1;
    float dy = y2-y1;
    float length = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float delx = dx/length;
    float dely = dy/length;

    float x = x1 + 0.5*sign(delx);
    float y = y1 + 0.5*sign(dely);

    for(int i=0; i<= length; i++){
        image.setPixel(x,y,value);
        x += delx;
        y += dely;
    }

}

void MainWindow::bresenham(float x1, float y1, float x2, float y2)
{
    QRgb value;
    value=qRgb(0,255,0);
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

       image.setPixel(x,y,value);

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

void MainWindow::circle(float r, float x, float y){
    QRgb value;
    value=qRgb(0,255,0);
    for(int i=x-r; i<=x+r; i++){
        image.setPixel(i,y-sqrt((r*r)-(i-x)*(i-x)),value);
        image.setPixel(i,y+sqrt((r*r)-(i-x)*(i-x)),value);
    }
    for(int i=y-r; i<=y+r; i++){
        image.setPixel(x-sqrt((r*r)-(i-y)*(i-y)),i,value);
        image.setPixel(x+sqrt((r*r)-(i-y)*(i-y)),i,value);
    }
}

void MainWindow::mh(int &xi, int &deli){
    xi++;
    deli += (2*xi)+1;
}

void MainWindow::md(int &xi, int &yi, int &deli){
    xi++;
    yi--;
    deli += (2*xi) - (2*yi) + 2;
}

void MainWindow::mv(int &yi, int &deli){
    yi--;
    deli -= (2*yi)+1;
}

void MainWindow::bCircle(int r, int x, int y){
    QRgb value;
    value = qRgb(0,255,0);
    int xi=0;
    int yi=r;
    int deli=2*(1-r);
    int d1, d2;

    while(yi>=0){

        image.setPixel(x+xi, y+yi, value);
        image.setPixel(x+xi, y-yi, value);
        image.setPixel(x-xi, y+yi, value);
        image.setPixel(x-xi, y-yi, value);
        if(deli<0){
            d1 = (2*deli) + (2*yi) - 1;
            if(d1<=0)
                mh(xi,deli);
            else
                md(xi,yi,deli);
        }
        else if(deli>0){
            d2 = (2*deli) - (2*xi) - 1;
            if(d2<=0)
                md(xi,yi,deli);
            else
                mv(yi,deli);
        }
        else if(deli==0)
            md(xi,yi,deli);
    }
}

void MainWindow::ddaCircle(float r, float x, float y){
    QRgb value;
    value = qRgb(0,255,0);
    int i=0, val;
    float e;

    do{
        val = pow(2,i);
        i++;
    }
    while(val<r);

    e = 1/pow(2,i-1);

    float stx = r, sty = 0, x1 = stx, y1 = sty,x2,y2;

    do{
        x2 = x1 + (e*y1);
        y2 = y1 - (e*x2);
        image.setPixel(x+x2,y+y2,value);
        image.setPixel(x+x2,y-y2,value);
        image.setPixel(x-x2,y+y2,value);
        image.setPixel(x-x2,y-y2,value);
        x1 = x2;
        y1 = y2;
    }
    while((y1-sty) < e || (stx-x1) > e);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{int x1,y1,x2,y2;
    x1=ui->textEdit->toPlainText().toFloat();
    y1=ui->textEdit_2->toPlainText().toFloat();
    x2=ui->textEdit_3->toPlainText().toFloat();
    y2=ui->textEdit_4->toPlainText().toFloat();
        dda(x1,y1,x2,y2);
            ui->label->setPixmap(QPixmap::fromImage(image));
            ui->label->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    int x,y,r;
    x=ui->textEdit_6->toPlainText().toInt();
    y=ui->textEdit_7->toPlainText().toInt();
    r=ui->textEdit_5->toPlainText().toInt();
        bCircle(r,x,y);
        ddaCircle(r*sin(M_PI/6),x,y);
            ui->label->setPixmap(QPixmap::fromImage(image));
            ui->label->show();

}
