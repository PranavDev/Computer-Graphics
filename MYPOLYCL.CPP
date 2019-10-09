#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<iostream.h>
#include<graphics.h>

int Xmin,Ymin,Xmax,Ymax,i=0,j=0,X[20],poly[10][10],edges,A[20];

void ClipLeft(int x1,int y1,int x2,int y2)
{
  if(x1>=Xmin && x2>=Xmin)
  {
     A[i] = x1;
     A[i+1] = y1;
     A[i+2] = x2;
     A[i+3] = y2;
     i++;
  }
  else if(x1<Xmin && x2>=Xmin)
  {
     A[i] = x2;
     A[i+1] = y2;
     i++;
  }
  else if(x1>=Xmin && x2<Xmin)
  {
     A[i] = x1;
     A[i+1] = y1;
     i++;
  }
  else
  {

  }
}


int main()
{
  int gdriver = DETECT,gmode;
  initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");

  cout<<"Window : ";
  cout<<"\nEnter the Xmin,Ymin : ";
  cin>>Xmin>>Ymin;
  cout<<"\nEnter the Xmax,Ymax : ";
  cin>>Xmax>>Ymax;

  cout<<"\nPolygon : ";
  cout<<"\nEnter the No. of Edges : ";
  cin>>edges;

  int i,j,X[20],k=0;

  for(i=0;i<edges;i++)
  {
     for(j=0;j<2;j++)
     {
	cout<<"\nA["<<i<<"]["<<j<<"] : ";
	cin>>poly[i][j];
	X[k++] = poly[i][j];
     }
  }

  cleardevice();

  cout<<"\nThe UnClipped Polygon : ";
  setcolor(WHITE);
  fillpoly(edges,X);

  setcolor(BLUE);
  rectangle(Xmin,Ymin,Xmax,Ymax);

  for(i=0;i<2*edges;i+=2)
  {
    ClipLeft(X[i%6],X[(i+1)%6],X[(i+2)%6],X[(i+3)%6]);
  }


  getch();

  cleardevice();

  return 0;
}
