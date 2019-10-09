#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<dos.h>
#include<graphics.h>

#define pi 3.141592654

int Xtop = 250,Ytop = 200;
int Xbot = 250,Ybot = 400;

void PendulumStrike(int rad)
{
   int Xt=Xtop,Yt=Ytop,Xb=Xbot,Yb=Ybot;
   int i;

   while(!kbhit())
   {
     i = 315;
     while(i<=360 && !kbhit())
     {
	line(Xt,Yt,Xb,Yb);
	circle(Xb,Yb,rad);
	line(Xt-rad-rad,Yt,Xb-rad-rad,Yb);
	circle(Xb-rad-rad,Yb,rad);

	line(Xt+(2*rad),Yt,Xb+(2*rad),Yb);
	circle(Xb+(2*rad),Yb,rad);

	line(Xtop-(4*rad),Ytop,Xbot-(4*rad),Ybot);
	circle(Xbot-(4*rad),Ybot,rad);
	Xbot = Xtop + 200*sin(i*pi/180);
	Ybot = Ytop + 200*cos(i*pi/180);
	if(i==360)
	{
	   i = 360;

	   while(i<=405 && !kbhit())
	   {
	      line(Xt,Yt,Xb,Yb);
	      circle(Xb,Yb,rad);
	      line(Xt-rad-rad,Yt,Xb-rad-rad,Yb);
	      circle(Xb-rad-rad,Yb,rad);

	      line(Xt-(4*rad),Yt,Xb-(4*rad),Yb);
	      circle(Xb-(4*rad),Yb,rad);

	      line(Xtop+(2*rad),Ytop,Xbot+(2*rad),Ybot);
	      circle(Xbot+(2*rad),Ybot,rad);
	      Xbot = Xtop + 200*sin(i*pi/180);
	      Ybot = Ytop + 200*cos(i*pi/180);
	      i++;
	      delay(10);
	      cleardevice();
	   }
	}
	else
	{
	   i++;
	   delay(10);
	   cleardevice();
	}
     }

     i = 405;
     while(i>=360 && !kbhit())
     {
	line(Xt,Yt,Xb,Yb);
	circle(Xb,Yb,rad);
	line(Xt-rad-rad,Yt,Xb-rad-rad,Yb);
	circle(Xb-rad-rad,Yb,rad);

	line(Xt-(4*rad),Yt,Xb-(4*rad),Yb);
	circle(Xb-(4*rad),Yb,rad);

	line(Xtop+(2*rad),Ytop,Xbot+(2*rad),Ybot);
	circle(Xbot+(2*rad),Ybot,rad);
	Xbot = Xtop + 200*sin(i*pi/180);
	Ybot = Ytop + 200*cos(i*pi/180);
	if(i==360)
	{
	   while(i>=315 && !kbhit())
	   {
	      line(Xt,Yt,Xb,Yb);
	      circle(Xb,Yb,rad);
	      line(Xt-rad-rad,Yt,Xb-rad-rad,Yb);
	      circle(Xb-rad-rad,Yb,rad);

	      line(Xt+(2*rad),Yt,Xb+(2*rad),Yb);
	      circle(Xb+(2*rad),Yb,rad);

	      line(Xtop-(4*rad),Ytop,Xbot-(4*rad),Ybot);
	      circle(Xbot-(4*rad),Ybot,rad);
	      Xbot = Xtop + 200*sin(i*pi/180);
	      Ybot = Ytop + 200*cos(i*pi/180);
	      i--;
	      delay(10);
	      cleardevice();
	   }
	}
	else
	{
	   i--;
	   delay(10);
	   cleardevice();
	}
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

   PendulumStrike(rad);

   getch();
   return 0;
}