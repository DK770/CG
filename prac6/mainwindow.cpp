#include "mainwindow.h"
#include "ui_mainwindow.h"

QImage image(500, 500, QImage::Format_RGB888);


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

void MainWindow::on_pushButton_clicked()
{
    int x1,y1,x2,y2;
    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();
    bresenham(x1,y1,x2,y2);
    ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::bresenham(int x1,int y1,int x2,int y2)
{
     QRgb value;
     value=qRgb(0,255,0);
     int x,y,dx,dy,p,s1,s2,interchange=0;
     x=x1;y=y1;
     dx=abs(x2,x1);
     dy=abs(y2,y1);
     s1=sign(x2-x1);
     s2=sign(y2-y1);

    /* if(dy>dx)
    {
         int temp=dx;
         dx=dy;
         dy=temp;
    interchange=1;
    }
    p=2*dy-dx;
    for(int i=0;i<dx;i++)
    {
         image.setPixel(x,y,value);
         while(p>=0){
             p=p-2*dx;
             if(interchange){
                 x+=s1;
                 x+=s1;
             }
             else{
                 y+=s2;
                 y+=s2;
             }
         }
         p=p+2*dy;
         if(interchange){
             y+=s2;
             y+=s2;
         }
         else{
             x+=s1;
             y+=s1;
         }
     }*/
     if(dx>=dy)
     {
         p=2*dy-dx;
         while(x!=x2)
         {
             if(p<0)
                 p+=2*dy;
             else
             {
                 p+=2*dy-2*dx;
                 y+=s2;
             }
             x+=s1;
             image.setPixel(x,y,value);

         }
     }
}

int MainWindow::abs(int a,int b)
{
    return a-b>0?a-b:-(a-b);
}

int MainWindow::sign(int a)
{
    if(a>=0)
        return 1;
    else
        return -1;
}
