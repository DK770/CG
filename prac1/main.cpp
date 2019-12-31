#include "mainwindow.h"
#include <QApplication>
#include<QtGui>
#include<cmath>

template<class T>
T sign(T var)
{
    if(var<0)
        return -1;
    else if(var>0)
        return 1;
    else
        return 0;
}

int floor(float var)
{
    int ret;
    ret=(int)var;
    return ret;
}

QImage drawline(float x1,float y1,float x2,float y2,QImage image)
{
    QRgb value;
    value=qRgb(0,255,0);

    float x,y,dx,dy;
    float length;
    //step2
        if(abs(x2-x1)>=abs(y2-y1))
            length=fabs(x2-x1);
        else
            length=fabs(y2-y1);

    //step3
        dx=(x2-x1)/length;
        dy=(y2-y1)/length;

    //step4
        x=x1+0.5*sign(dx);
        y=y1+0.5*sign(dy);

    //step5
        float i=0;
        while (i<length)
        {
                image.setPixel(x,y,value);
                x=x+dx;
                y=y+dy;
                i++;
        }
        return image;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QImage image(600, 600, QImage::Format_RGB888);

/*
    float x1,x2,y1,y2;
    x1=100;
    y1=100;
    x2=500;
    y2=500;
*/
    //outer square
    image = drawline(100,100,500,100,image);
    image = drawline(100,100,100,500,image);
    image = drawline(100,500,500,500,image);
    image = drawline(500,100,500,500,image);
    //diamond
    image = drawline(300,100,100,300,image);
    image = drawline(300,100,500,300,image);
    image = drawline(300,500,100,300,image);
    image = drawline(300,500,500,300,image);
    //inner square
    image = drawline(200,200,400,200,image);
    image = drawline(200,200,200,400,image);
    image = drawline(400,200,400,400,image);
    image = drawline(200,400,400,400,image);

    QLabel l;
    l.setPixmap(QPixmap::fromImage(image));
    l.show();

    return a.exec();
}


