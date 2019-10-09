#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include<dos.h>
#include<process.h>
#include<graphics.h>

#define Y getmaxy()
#define X getmaxx()


void BounceBall(float Xg,float Yg,float rad,int bounces)
{
  int i = 0,initial,final;
  float Xc,Yc;
  float Ycnew,Ydown,Yup;

  Xc = Xg/2;

  while(i<bounces && !kbhit())
  {
    Yc = Yg - 100;

    Ycnew = Yc + rad;
    initial = Yc;
    final = Yg;
    Ydown = 0;
    Yup = 0;

    if(Ycnew<=final)
    {
      while (Ycnew<=final)
      {
	delay(20);

	clearviewport();

	setcolor(WHITE);
	line(0,Yg,Xg,Yg);

	setcolor(RED);
	circle(Xc,Yc + Ydown,rad);

	Ycnew+=2;
	Ydown+=2;
      }
      i++;
    }
    else if(Ycnew==Yg)
    {
      while(Ycnew>=initial)
      {
	delay(20);
	clearviewport();

	setcolor(WHITE);
	line(0,Yg,Xg,Yg);

	setcolor(RED);
	circle(Xc,Yc - Yup,rad);

	 Ycnew-=2;
	 Yup-=2;
      }
    }
  }
}


int main()
{
  int gdriver = DETECT,gmode;
  initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");

  float rad,Xg,Yg;
  int bounces;

  cout<<"\t\tBouncing Ball Animation";
  cout<<"\nEnter the Radius Of the Ball : ";
  cin>>rad;
  cout<<"\nEnter the No. of Bounces : ";
  cin>>bounces;

  //for the Ground below the Ball
  Yg = getmaxy()/1.5;
  Xg = getmaxx();

  cleardevice();

  BounceBall(Xg,Yg,rad,bounces);

  getch();
  closegraph();

  return 0;
}