#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
#include<process.h>
#include<math.h>
#include<iostream.h>
#include<graphics.h>

class Clip
{
  public:
	 int Pedges,Wedges,Polygon[10][10],Window[10][10];
	 void acceptPoly(int Pedges);
	 void plotPoly(int Pedges);
	 void acceptWindow(int Wedges);
	 void plotWindow(int Wedges);
	 void CohenSuth();
};

void Clip::acceptPoly(int Pedges)
{
   int i,j;
   for(i=1;i<=Pedges;i++)
   {
      for(j=1;j<=2;j++)
      {
	 cout<<"Polygon["<<i<<"]["<<j<<"] : ";
	 cin>>Polygon[i][j];
      }
   }
}

void Clip::acceptWindow(int Wedges)
{
   int i,j;
   for(i=1;i<=Wedges;i++)
   {
      for(j=1;j<=2;j++)
      {
	 cout<<"Window["<<i<<"]["<<j<<"] : ";
	 cin>>Window[i][j];
      }
   }
}

void Clip::plotPoly(int Pedges)
{
   int i;
   for(i=1;i<Pedges;i++)
   {
      delay(2);
      line(Polygon[i][0],Polygon[i][1],Polygon[i+1][0],Polygon[i+1][1]);
   }
   line(Polygon[i][0],Polygon[i][1],Polygon[Pedges][0],Polygon[Pedges][1]);
}

void Clip::plotWindow(int Wedges)
{
   int i;
   for(i=1;i<Wedges;i++)
   {
      delay(2);
      line(Window[i][0],Window[i][1],Window[i+1][0],Window[i+1][1]);
   }
   line(Window[i][0],Window[i][1],Window[Wedges][0],Window[Wedges][1]);
}


int main()
{
  int gdriver = DETECT,gmode;
  initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");

  int Pedges,Wedges;
  Clip c;

  cout<<"Enter the No. of Edges for the Polygon : ";
  cin>>Pedges;
  c.acceptPoly(Pedges);
  c.plotPoly(Pedges);

  cout<<"\nEnter the No. of Edges for Window : ";
  cin>>Wedges;
  c.acceptWindow(Wedges);
  cleardevice();
  c.plotWindow(Wedges);

  cleardevice();
  c.plotPoly(Pedges);
  c.plotWindow(Wedges);

  cout<<"\nNow We Perform Interior Clipping : ";
  //CohenSuth();

  return 0;
}
