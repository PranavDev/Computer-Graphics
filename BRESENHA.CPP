#include<iostream.h>
#include<math.h>
#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>

int sign(float arg);
void Bresenham(int x1,int x2,int y1,int y2);

void main()
{
   int gdriver = DETECT,gmode;
   int x1,y1,x2,y2,N,i;
   initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");

   cout<<"Enter the No. of Sides : ";
   cin>>N;

   for(i=0;i<N;i++)
   {
     cout<<"Bresenham Alogrithm";
     cout<<"Enter the Starting Co-ordinates : ";
     cin>>x1>>y1;
     cout<<"Enter the End Co-ordinates : ";
     cin>>x2>>y2;

     Bresenham(x1,y1,x2,y2);
   }

   getch();
   closegraph();
}

void Bresenham(int x1,int y1,int x2,int y2)
{
   int s1,s2,flag,x,y,i;
   int dx,dy,G,temp;

   dx = (x2-x1);
   dy = (y2-y1);

   x = x1;
   y = y1;

   s1 = sign(x2-x1);
   s2 = sign(y2-y1);

   if(dy>dx)
   {
     temp = dx;
     dx = dy;
     dy = temp;
     flag = 1;
   }
   else
   {
     flag = 0;
   }

   G = (2*dy)-dx;
   i = 1;

   while(i<=dx)
   {
     putpixel(x,y,1);
     delay(5);
     while(G>=0)
     {
       if(flag==1)
       {
	 x = x+s1;
       }
       else
       {
	 y = y+s2;
       }
       G = G+(2*dy)-(2*dx);
     }
     if(flag==1)
     {
       y = y+s2;
     }
     else
     {
       x = x+s1;
     }
     G = G+(2*dy);
     i++;
   }
}

int sign(float arg)
{
  if(arg<0)
  {
    return -1;
  }
  else if(arg==0)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}