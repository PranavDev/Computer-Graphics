#include<iostream.h>
#include<graphics.h>
#include<dos.h>
#include<conio.h>
#include<process.h>

class Fill
{
  public:
	//int poly[10][2];
	//void getPoly(int edges);
	//void PlotPoly(int edges,int poly[10][2]);
	void boundaryfill(int x,int y,int newColor,int bckgColor);
	void floodfill(int x,int y,int newColor);
	void edgefill();
	void fencefill();
};

/*void Fill::getPoly(int edges)
{
  int i,j;
  for(i=1;i<=edges;i++)
  {
    for(j=1;j<=2;j++)
    {
      cout<<"\nA["<<i<<"]["<<j<<"] : ";
      cin>>poly[i][j];
    }
  }
  cleardevice();
}*/


/*void Fill::PlotPoly(int edges,int poly[10][2])
{
  int i,j=edges;
  for(i=1;i<=edges;i++)
  {
    delay(2);
    line(poly[i][1],poly[i][2],poly[i+1][1],poly[i+1][2]);
  }
  line(poly[1][1],poly[1][2],poly[j][1],poly[j+1][2]);
}*/

void Fill::boundaryfill(int x,int y,int newColor,int bckgColor)
{
  int current;
  current = getpixel(x,y);

  if((current!=newColor) && (current!=bckgColor))
  {
    delay(1);
    putpixel(x,y,newColor);
    boundaryfill(x+1,y,newColor,bckgColor);
    boundaryfill(x-1,y,newColor,bckgColor);
    boundaryfill(x,y+1,newColor,bckgColor);
    boundaryfill(x,y-1,newColor,bckgColor);
  }
}

void Fill::floodfill(int x,int y,int newColor)
{
  int current;
  current = getpixel(x,y);

  if(current!=newColor)
  {
    delay(1);
    putpixel(x,y,newColor);
    floodfill(x+1,y,newColor);
    floodfill(x-1,y,newColor);
    floodfill(x,y+1,newColor);
    floodfill(x,y-1,newColor);
  }
}

//main() begins...

int main()
{
  int ch,edges,newCol,bckgCol,i,j,x,y;
  //int poly[10][2];
  int gdriver = DETECT,gmode;
  initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");

  Fill f;

  /*cout<<"Enter the No. Of Polygon Edges : ";
  cin>>edges;*/

  /*for(i=1;i<=edges;i++)
  {
    for(j=1;j<=2;j++)
    {
      cout<<"\nA["<<i<<"]["<<j<<"] : ";
      cin>>poly[i][j];
    }
  }*/

  //f.getPoly(edges);
  cleardevice();
  //f.PlotPoly(edges,poly);


  cout<<"\nEnter the Previous BackGround Color : ";
  cin>>bckgCol;
  cout<<"\nEnter the Color to be Filled : ";
  cin>>newCol;

  cout<<"\nFilling Algorithms : ";
  cout<<"\n1.Boundary Fill.";
  cout<<"\n2.Flood Fill.";
  cout<<"\n3.Edge Fill.";
  cout<<"\n4.Fence Fill.";
  cout<<"\n5.Exit.";
  cout<<"\n\nEnter Your Choice : ";
  cin>>ch;

  switch(ch)
  {
     case 1 : cout<<"\n\nYou Selected Boundary Fill Algorithm!";
	      x = 125;
	      y = 112;
	      cleardevice();
	      rectangle(100,100,150,125);
	      f.boundaryfill(x,y,newCol,bckgCol);
	      break;

     case 2 : cout<<"\n\nYou Selected Flood Fill Algorithm!";
	      //i = j = 1;
	      //x = poly[i][j] + 50;
	      //y = poly[i][j+1] + 50;
	      x = 125;
	      y = 112;
	      cleardevice();
	      rectangle(100,100,150,125);
	      f.floodfill(x,y,newCol);
	      break;

     case 3 : cout<"\n\nYou Selected Edge Fill Algorithm!";
	      break;

     case 5 : exit(1);

     default : cout<<"\nWrong Choice!";
	       break;
  }
  closegraph();
  return 0;
}