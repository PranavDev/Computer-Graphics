#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<process.h>
#include<graphics.h>

void PlotCuboid(int l,int h,int b)
{
   delay(50);
   line(300,300,300,300-h);
   delay(50);
   line(300,300-h,300+l,300-h);
   delay(50);
   line(300+l,300-h,300+l,300);
   delay(50);
   line(300+l,300,300,300);

   delay(50);
   line(300-b,300+b,300-b,300+b-h);
   delay(50);
   line(300-b,300+b-h,300-b+l,300+b-h);
   delay(50);
   line(300-b+l,300+b-h,300-b+l,300+b);
   delay(50);
   line(300-b+l,300+b,300-b,300+b);

   delay(50);
   line(300-b,300+b-h,300,300-h);
   delay(50);
   line(300-b+l,300+b-h,300+l,300-h);
   delay(50);
   line(300-b,300+b,300,300);
   delay(50);
   line(300-b+l,300+b,300+l,300);
}


int main()
{
   int gdriver = DETECT,gmode;
   initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");

   int x,y,z,Sx,Sy,Sz;

   cout<<"\t\tCUBOID DISPLAY : ";
   cout<<"\nEnter the Value of X (length) : ";
   cin>>x;
   cout<<"\nEnter the Value of Y (height) : ";
   cin>>y;
   cout<<"\nEnter the Value of Z (width) : ";
   cin>>z;

   cleardevice();

   PlotCuboid(x,y,z);

   cout<<"\t\tScaling : ";
   cout<<"\nEnter the Sx : ";
   cin>>Sx;
   cout<<"\nEnter the Sy : ";
   cin>>Sy;
   cout<<"\nEnter the Sz : ";
   cin>>Sz;

   x = Sx*x;
   y = Sy*y;
   z = Sz*z;

   cleardevice();

   PlotCuboid(x,y,z);

   getch();
   closegraph();

   return 0;
}