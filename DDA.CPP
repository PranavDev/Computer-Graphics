#include<stdio.h>
#include<stdlib.h>
#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>

void DDA(int x1,int y1,int x2,int y2);

void main()
{
   int gdriver = DETECT,gmode;
   initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
   int i;
   int x1,y1,x2,y2;

   cout<<"DDA - Rectangular Tap Construction";

   for(i=0;i<1;i++)
   {
     cout<<"\nEnter the Starting Co-ordinates : ";
     cin>>x1>>y1;
     cout<<"Enter the Ending Co-ordinates : ";
     cin>>x2>>y2;
     DDA(x1,y1,x1+90,y1);
     DDA(x1,y1,x1,y1+100);
     DDA(x1+90,y1,x2,y2);
     DDA(x1,y1,x1,y1+100);
     DDA(x1,y1+100,x2,y2);
   }
   for(i=0;i<2;i++)
   {
     cout<<"Enter the Starting Co-ordinates : ";
     cin>>x1>>y1;
     cout<<"Enter the Ending Co-ordinates : ";
     cin>>x2>>y2;
     DDA(x1,y1,x1+50,y1);
     DDA(x1,y1,x1,y1+50);
     DDA(x1+50,y1,x2,y2);
     DDA(x1,y1+50,x2,y2);
   }
   for(i=0;i<1;i++)
   {
     cout<<"Enter the Starting Co-ordinates : ";
     cin>>x1>>y1;
     cout<<"Enter the Ending Co-ordinates : ";
     cin>>x2>>y2;
     DDA(x1,y1,x1+100,y1);
     DDA(x1,y1,x1,y1+25);
     DDA(x1+100,y1,x2,y2);
     DDA(x1,y1+25,x2,y2);
   }

   for(i=0;i<1;i++)
   {
     cout<<"Enter 1st Starting Co-ordinates : ";
     cin>>x1>>y1;
     cout<<"Enter 2nd Starting Co-ordinates : ";
     cin>>x2>>y2;
     DDA(x1,y1,x1+90,y1);
     DDA(x2,y2,x2+50,y2);
     DDA(x2+50,y2,x2+50,y2+50);
     DDA(x1+90,y1,x1+90,y1+100);
     DDA(x2+50,y2+50,x1+90,y1+100);
   }

   getch();
   closegraph();
}

void DDA(int x1,int y1,int x2,int y2)
{
   int i,dx,dy,steps;
   float x,y;
   float Xinc,Yinc;

   dx = (x2-x1);
   dy = (y2-y1);

   if(abs(dx)>=abs(dy))
   {
     steps = dx;
   }
   else
   {
     steps = dy;
   }

   Xinc = (float)dx/steps;
   Yinc = (float)dy/steps;

   x = x1;
   y = y1;

   putpixel(x,y,1);

   for(i=1;i<steps;i++)
   {
     delay(5);
     x = x+Xinc;
     y = y+Yinc;
     putpixel(x,y,1);
   }
}