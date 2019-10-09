#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<iostream.h>
#include<dos.h>
#include<graphics.h>

void Bresenham(int,int,int,int);

int main()
{
   int gdriver = DETECT,gmode;
   initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");

   int x1,y1,x2,y2;

   cout<<"Enter the x1 and y1 : ";
   cin>>x1>>y1;
   cout<<"\nEnter the x2 and y2 : ";
   cin>>x2>>y2;

   Bresenham(x1,y1,x2,y2);

   getch();
   closegraph();

   return 0;
}

int sign(float res)
{
   if(res>0)
   {
     return 1;
   }
   else if(res<0)
   {
     return -1;
   }
   else
   {
     return 0;
   }
}

void Bresenham(int x1,int y1,int x2,int y2)
{
   int x,y,s1,s2,i,exchange;
   float dx,dy,g,temp;

   dx = abs(x2-x1);
   dy = abs(y2-y2);

   x = x1;
   y = y1;

   s1 = sign(x2-x1);
   s2 = sign(y2-y1);

   if(dy>dx)
   {
     temp = dx;
     dx = dy;
     dy = temp;
     exchange = 1;
   }
   else
   {
     exchange = 0;
   }
   i = 1;
   g = 2*dy-dx;

   while(i<=dx)
   {
     putpixel(x,y,1);

     delay(10);
     while(g>=0)
     {
       if(exchange==1)
       {
	 x = x + s1;
       }
       else
       {
	 y = y + s2;
       }
       g = g + 2*dy - 2*dx;
     }
     if(exchange==1)
     {
       y = y + s2;
     }
     else
     {
       x = x + s1;
     }
     g = g + 2*dy;
     i++;
   }
}