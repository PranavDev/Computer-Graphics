#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<math.h>
#include<process.h>
#include<graphics.h>

#define X getmaxx()
#define Y getmaxy()
#define root2 1.141213562

void CreateCar(float Xc,float Yc,float Yh,float Yd)
{
  int Xo = 0,i = 0;
  float yc,xc;
  int Wx = 410;
  int Wy = Yh - 70;
  float h = 0.0;

  while(!kbhit())
  {
     delay(1);
     //Sun Design
     setcolor(YELLOW);
     circle(400,Yh/3,20);
     yc = Yh/3;
     xc = 400;

     line(xc,yc-25,xc,yc-35);
     line(xc,yc+25,xc,yc+35);
     line(xc-25,yc,xc-35,yc);
     line(xc+25,yc,xc+35,yc);

     //Mountains Design
     delay(2);
     setcolor(WHITE);
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
     line(480,Yh,550,Yh-100);
     line(550,Yh-100,630,Yh);

     //Road Lines Design
     delay(2);
     setcolor(WHITE);
     line(0,Yc,Xc,Yc);
     line(0,Yd,50,Yd);
     line(100,Yd,150,Yd);
     line(200,Yd,250,Yd);
     line(300,Yd,350,Yd);
     line(400,Yd,450,Yd);
     line(500,Yd,550,Yd);

     //Car Design
     delay(1);
     setcolor(WHITE);
     line(Xo,Yc-20,Xo+20,Yc-20);
     circle(Xo+40,Yc-20,20);
     circle(Xo+40,Yc-20,0);
     line(Xo+60,Yc-20,Xo+90,Yc-20);
     circle(Xo+110,Yc-20,20);
     circle(Xo+110,Yc-20,0);
     line(Xo+130,Yc-20,Xo+160,Yc-20);
     line(Xo,Yc-20,Xo,Yc-40);
     line(Xo,Yc-40,Xo+40,Yc-60);
     line(Xo+40,Yc-60,Xo+110,Yc-60);
     line(Xo+110,Yc-60,Xo+140,Yc-40);
     line(Xo+140,Yc-40,Xo+160,Yc-40);
     line(Xo+160,Yc-40,Xo+160,Yc-20);


     Xo+=10;

     //windmills
     delay(100);
     clearviewport();
     setcolor(WHITE);
     line(410,Yh-70,410,Yh);
     line(411,Yh-70,411,Yh);
     setcolor(RED);
     circle(410,Yh-70,2);
     setcolor(WHITE);
     if(i%2==0)
     {
	line(Wx-25+(25/root2),Wy-(25/root2),Wx+25-(25/root2),Wy+(25/root2));
	line(Wx+(25/root2),Wy-25+(25/root2),Wx-(25/root2),Wy+25-(25/root2));
     }
     else
     {
	line(Wx-25,Wy,Wx+25,Wy);
	line(Wx,Wy-25,Wx,Wy+25);
     }
     i+=3;
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