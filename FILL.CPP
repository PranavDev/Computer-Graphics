#include<stdlib.h>
#include<conio.h>
#include<iostream.h>
#include<dos.h>
#include<graphics.h>

#define max 10000
void push(int);
int pop();
int top = -1;
int Stack[max];
int current,m;

void Bresenham(int x,int y,int r);
void BoundaryFill(int x,int y,int newcolor);
void FloodFill(int x,int y,int newcolor);
void display(int,int,int,int);

int main()
{
   int gdriver = DETECT,gmode;
   initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");

   int r,x,y;

   cout<<"Stack for Boundary Fill and Flood Fill";

   cout<<"\nEnter the radius of the Circle : ";
   cin>>r;

   cout<<"\nEnter the x1 and y1 : ";
   cin>>x>>y;

   cleardevice();

   //Bresenham(x,y,r);

   circle(x,y,r);
   BoundaryFill(x,y,15);

   cleardevice();

   circle(x,y,r);
   FloodFill(x,y,15);
   //push(x);
   //push(y);

   getch();
   closegraph();

   return 0;
}


void Bresenham(int x,int y,int r)
{
  int x1,y1;
  float dp;

  x1 = 0;
  y1 = r;
  dp = 3 - 2*r;

  while(x1<=y1)
  {
    if(dp<=0)
    {
      x1++;
      dp = dp + 4*x1 + 6;
    }
    else
    {
      x1++;
      y1--;
      dp = dp + 4*(x1 - y1) + 10;
    }
    display(x1,y1,x,y);
  }
}

void display(int x1,int y1,int x,int y)
{
  putpixel(x1+x,y1+y,1);
  putpixel(x1+x,y-y1,1);
  putpixel(x-x1,y1+y,1);
  putpixel(x-x1,y-y1,1);
  putpixel(y1+x,x1+y,1);
  putpixel(y1+x,y-x1,1);
  putpixel(x-y1,x1+y,1);
  putpixel(x-y1,y-x1,1);
}

void BoundaryFill(int x,int y,int newcolor)
{
  current = getpixel(x,y);
  if(current!=newcolor && current!=1)
  {
    delay(1);
    putpixel(x,y,newcolor);
    BoundaryFill(x+1,y,newcolor);
    BoundaryFill(x,y+1,newcolor);
    BoundaryFill(x-1,y,newcolor);
    BoundaryFill(x,y-1,newcolor);
  }
}

void FloodFill(int x,int y,int newcolor)
{

}

void push(int p)
{
  if(top==max)
  {
    cout<<"\nStack Full!";
  }
  else
  {
    top++;
    Stack[top] = p;
  }
}

int pop()
{
  if(top==-1)
  {
    cout<<"\nStack Empty!";
  }
  else
  {
    m = Stack[top];
    top--;
  }
  return m;
}