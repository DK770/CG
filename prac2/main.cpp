#include "mainwindow.h"
#include <bits/stdc++.h>
#include <QApplication>
#include <QWidget>
#include <QtGui>
#include <QThread>
#define M_PI 3.14159265358979323846
 //QImage image(500, 500, QImage::Format_RGB888);
/*template<class T>
T sign(T x){
    if(!x)
        return 0;
    if(x>0)
        return 1;
    return -1;
}

void dda(float x1, float y1, float x2, float y2, QImage &image)
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

void bresenham(float x1, float y1, float x2, float y2,QImage &image)
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

void circle(float r, float x, float y, QImage &image){
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

void mh(int &xi, int &deli){
    xi++;
    deli += (2*xi)+1;
}

void md(int &xi, int &yi, int &deli){
    xi++;
    yi--;
    deli += (2*xi) - (2*yi) + 2;
}

void mv(int &yi, int &deli){
    yi--;
    deli -= (2*yi)+1;
}

void bCircle(int r, int x, int y, QImage &image){
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

void ddaCircle(float r, float x, float y, QImage &image){
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
}*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

  //  float r=200; //Radius of outer circle

    //QImage image(500, 500, QImage::Format_RGB888);

   // float x=250,y=250;

    //Outer circle
 //   bCircle(r,x,y,image);

    //Triangle
  /*  dda(x,y-r,x-r*(cos(M_PI/6)),y+r*sin(M_PI/6),image);

    dda(x,y-r,x+r*(cos(M_PI/6)),y+r*sin(M_PI/6),image);

    dda(x+r*(cos(M_PI/6)),y+r*sin(M_PI/6),x-r*(cos(M_PI/6)),y+r*sin(M_PI/6),image);

    //Inner circle
    ddaCircle(r*sin(M_PI/6),x,y,image);

    QLabel l;
    l.setPixmap(QPixmap::fromImage(image));
    l.show();
    */

    return a.exec();
}
