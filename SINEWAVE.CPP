#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>

void mid_pt_SineWave(int x1,int y1,int r,int count);
void display(int,int,int,int,int);

void main()
{
  int gdriver = DETECT,gmode;
  initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");

  int i,x,y,r,n;
  int count = 0;

  cout<<"**Sine Wave Generation using Mid-Point Method**";
  cout<<"\nEnter No. of Waves : ";
  cin>>n;

  for(i=0;i<n;i++)
  {
     cout<<"\nEnter the Co-ordinates : ";
     cin>>x>>y;
     cout<<"Enter radius : ";
     cin>>r;
     count++;
     mid_pt_SineWave(x,y,r,count);
  }

  getch();
  closegraph();
}

void mid_pt_SineWave(int x,int y,int r,int count)
{
  int x1,y1;
  float dp;
  x1 = 0;
  y1 = r;
  dp = 1 - r;

  while(x1<=y1)
  {
    if(dp<=0)
    {
      x1++;
      dp+=(2*x1)+1;
    }
    else
    {
      x1++;
      y1--;
      dp+=2*(x1-y1)+1;
    }
    delay(15);
    display(x1,y1,x,y,count);
  }
}

void display(int x1,int y1,int x,int y,int count)
{
  if(count%2!=0)
  {
    putpixel(x1+x,y-y1,1);
    putpixel(x-x1,y-y1,1);
    putpixel(x+y1,y-x1,1);
    putpixel(x-y1,y-x1,1);
  }
  else
  {
    putpixel(x1+x,y1+y,1);
    putpixel(x-x1,y1+y,1);
    putpixel(x+y1,y+x1,1);
    putpixel(x-y1,y+x1,1);
  }
}