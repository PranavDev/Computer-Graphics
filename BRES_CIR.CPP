#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<math.h>
#include<graphics.h>

void circ_bres(int x,int y,int r);
void display(int x1,int y1,int x,int y);
void main()
{
   int gdriver = DETECT,gmode;
   initgraph(&gmode,&gdriver,"C:\\TURBOC3\\BGI");
   int x,y,r;
   cout<<"\nEnter the co-ordinates : ";
   cin>>x>>y;
   cout<<"\nEnter the radius : ";
   cin>>r;
   circ_bres(x,y,r);
   getch();
   closegraph();
}

void circ_bres(int x,int y,int r)
{
   float dp;
   int x1,y1;
   x1 = 0;
   y1 = r;

   dp = 3-(2*r);
   while(x1<=y1)
   {
      if(dp<=0)
      {
	 x1++;
	 dp = dp+(4*x1)+6;
      }
      else
      {
	 x1++;
	 dp = dp+(4*(x1-y1))+10;
	 y1--;
      }
   }
   display(x1,y1,x,y);
}

void display(int x1,int y1,int x,int y)
{
   putpixel(x1+x,y1+y,1);
   putpixel(x1+x,y1-y,1);
   putpixel(x-x1,y1+y,1);
   putpixel(x-x1,y-y1,1);
   putpixel(x+y1,y+x1,1);
   putpixel(x+y1,y-x1,1);
   putpixel(x-y1,y+x1,1);
   putpixel(x-y1,y-x1,1);
}