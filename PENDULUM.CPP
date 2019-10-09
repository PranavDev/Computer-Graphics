#include<iostream.h>
#include<dos.h>
#include<process.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>

#define pi 3.141592654

int Xtop = 320, Ytop = 200;
int Xbot = 320, Ybot = 400;

void Pendulum(int rad)
{
  int i;

  while(!kbhit())
  {
    i = 90;
    while(i>45 && !kbhit())
    {
       Xbot = Xtop + 200*cos(i*pi/180);
       Ybot = Ytop + 200*sin(i*pi/180);
       line(Xtop,Ytop,Xbot,Ybot);
       circle(Xbot,Ybot,rad);

       i--;
       delay(10);
       cleardevice();
    }
    i = 45;

    while(i<90 && !kbhit())
    {
       line(Xbot,Ybot,Xtop,Ytop);
       circle(Xbot,Ybot,rad);
       Xbot = Xtop + 200*cos(i*pi/180);
       Ybot = Ytop + 200*sin(i*pi/180);
       i++;
       delay(10);
       cleardevice();
    }
    i = 90;

    while(i<135 && !kbhit())
    {
       line(Xbot,Ybot,Xtop,Ytop);
       circle(Xbot,Ybot,rad);
       Xbot = Xtop + 200*cos(i*pi/180);
       Ybot = Ytop + 200*sin(i*pi/180);
       i++;
       delay(10);
       cleardevice();
    }
    i = 135;

    while(i>90 && !kbhit())
    {
       line(Xbot,Ybot,Xtop,Ytop);
       circle(Xbot,Ybot,rad);
       Xbot = Xtop + 200*cos(i*pi/180);
       Ybot = Ytop + 200*sin(i*pi/180);
       i--;
       delay(10);
       cleardevice();
    }
  }
}

int main()
{
  int gdriver = DETECT,gmode;
  initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");

  int rad;
  cout<<"Enter the Radius : ";
  cin>>rad;

  Pendulum(rad);

  getch();
  return 0;
}