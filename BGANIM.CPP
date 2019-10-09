#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<process.h>
#include<graphics.h>

#define X getmaxx()
#define Y getmaxy()

void CreateCar(float Xc,float Yc,float Yh,float Yd)
{
  int Xo = 0;
  float xlc = 1.5*X;
  float yc,xc;

  while(1 && xlc!=Xo && !kbhit())
  {
     delay(10);
     line(xlc,Yc-20,xlc-50,Yc-20);
     line(xlc-100,Yc-20,xlc-150,Yc-20);
     line(xlc-200,Yc-20,xlc-250,Yc-20);
     line(xlc-300,Yc-20,xlc-350,Yc-20);
     line(xlc-400,Yc-20,xlc-450,Yc-20);
     line(xlc-500,Yc-20,xlc-550,Yc-20);
     line(xlc-600,Yc-20,xlc-650,Yc-20);
     line(xlc-700,Yc-20,xlc-750,Yc-20);
     line(xlc-800,Yc-20,xlc-850,Yc-20);
     line(xlc-900,Yc-20,xlc-950,Yc-20);
     line(xlc-1000,Yc-20,xlc-1050,Yc-20);

     xlc-=2;
     clearviewport();

     line(0,Yh,X,Yh);
     line(0,Yh,30,Yh-20);
     line(30,Yh-20,60,Yh);
     line(60,Yh,110,Yh-40);
     line(110,Yh-40,160,Yh);
     line(150,Yh-20,230,Yh-70);
     line(230,Yh-70,305,Yh-20);
     line(300,Yh,350,Yh-40);
     line(350,Yh-40,410,Yh);
     line(410,Yh,445,Yh-20);
     line(445,Yh-20,480,Yh);

     circle(400,Yh/3,20);
     yc = Yh/3;
     xc = 400;
     delay(2);

     line(xc,yc-25,xc,yc-35);
     delay(2);
     line(xc,yc+25,xc,yc+35);
     delay(2);
     line(xc-25,yc,xc-35,yc);
     delay(2);
     line(xc+25,yc,xc+35,yc);
     clearviewport();

     line(0,Yc,Xc,Yc);
     line(Xo,Yc-20,Xo+20,Yc-20);
     circle(Xo+40,Yc-20,20);
     line(Xo+60,Yc-20,Xo+90,Yc-20);
     circle(Xo+110,Yc-20,20);
     line(Xo+130,Yc-20,Xo+160,Yc-20);
     line(Xo,Yc-20,Xo,Yc-40);
     line(Xo,Yc-40,Xo+40,Yc-60);
     line(Xo+40,Yc-60,Xo+110,Yc-60);
     line(Xo+110,Yc-60,Xo+140,Yc-40);
     line(Xo+140,Yc-40,Xo+160,Yc-40);
     line(Xo+160,Yc-40,Xo+160,Yc-20);
  }
}

int main()
{
  int gdriver = DETECT,gmode;
  initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");

  float Yc,Xc,Yh,Yd;

  Xc = X;
  Yc = Y/1.5;
  Yh = Y/2;
  Yd = Y/1.75;

  CreateCar(Xc,Yc,Yh,Yd);

  getch();
  closegraph();
  return 0;
}