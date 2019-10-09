#include<stdlib.h>
#include<conio.h>
#include<iostream.h>
#include<dos.h>
#include<graphics.h>

void BresLine(int x1,int y1,int x2,int y2);
void FenceFill_r(int,int,int);
void FenceFill_l(int,int,int);
int sign(float arg);

int main()
{
   int gdriver = DETECT,gmode;
   initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");

   int x1,y1,x2,y2,Xf,Yf;

   cout<<"\nEnter the x1 and y1 : ";
   cin>>x1>>y1;

   cout<<"\nEnter the x2 and y2 : ";
   cin>>x2>>y2;

   cleardevice();

   delay(10);
   BresLine(x1,y1,x2,y1);
   delay(10);
   BresLine(x2,y1,x2,y2);
   delay(10);
   BresLine(x2,y2,x1,y2);
   delay(10);
   BresLine(x1,y2,x1,y1);

   Xf = (x1+x2)/2;
   Yf = (y1+y2)/2;

   delay(10);
   BresLine(Xf,y1,Xf,Yf);

   //FenceFill_r(x1,y1,15);
   //FenceFill_l(x1,y1,15);

   getch();
   closegraph();

   return 0;
}


void BresLine(int x1,int y1,int x2,int y2)
{
  int s1,s2,x,y,i,exch;
  float g,temp,dx,dy;

  dx = abs(x2-x1);
  dy = abs(y2-y1);

  x = x1;
  y = y1;

  s1 = sign(x2-x1);
  s2 = sign(y2-y1);

  if(dy>dx)
  {
    temp = dx;
    dx = dy;
    dy = temp;
    exch = 1;
  }
  else
  {
    exch = 0;
  }

  i = 1;
  g = 2*dy - dx;

  while(i<=dx)
  {
    if(exch==1)
    {
      x1+=s1;
    }
    else
    {
      y1+=s2;
    }
    g = g + 2*dy - 2*dx;
  }

  if(exch==1)
  {
    y1+=s2;
  }
  else
  {
    x1+=s1;
  }
  g = g + 2*dy;
  i++;
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