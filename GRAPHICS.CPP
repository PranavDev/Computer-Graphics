#include<stdio.h>
#include<dos.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
void DDA(int ,int ,int ,int );
void Bresenham(int ,int ,int ,int );
void Object();

void main()
{
   int n,X1,X2,Y1,Y2,gd,gm,Dx,Dy,temp=0;
   gd=DETECT;
   initgraph(&gd,&gm,"C:/TURBOC3/BGI");

       printf("\n\tEnter your choice\n\t");
       printf("\n\t1) dda \n\t 2) breshenham\n\y\t \n\t 3) object \n\t 4)Exit");
       scanf("%d",&n);
   while(temp==0)
  {
   switch(n)
     {
     case 1:
     printf("Enter coordinates  \n");
     scanf("%d%d%d%d",&X1,&Y1,&X2,&Y2);
     DDA(X1,X2,Y1,Y2);
     printf("\n YO");
     break;

     case 2:
     printf("Enter coordinates  \n");
     scanf("%d%d%d%d",&X1,&Y1,&X2,&Y2);
     Bresenham(X1,X2,Y1,Y2);

     break;

     case 3:
     Object();
     break;

     case 4:
     temp=1;
     break;
     }
   }
   printf("\n\n THANK YOU");
}


void Bresenham(int x1,int y1,int x2,int y2)               //implementation of Bresenham algorithm
{
	int sign(int);
	int g,x,y,d,dy,dx,temp,s1,s2,flag=0,i=1;

	dx = abs(x2-x1);
	dy = abs(y2-y1);
	s1 = sign(x2-x1);
	s2 = sign(y2-y1);
	x = x1;
	y = y1;

	if(dy>dx)
	{
	 temp = dx;
	 dx = dy;
	 dy = temp;
	 flag = 1;
	}
	g = 2*dy-dx;
	while(i<dx)
	{
	   putpixel(x,y,3);
	   delay(10);
	   if(g>=0)
	   {
		if(flag==1)
			x = x + s1;
		else
		{
			y = y + s2;
			g = g + 2*dy - 2*dx;
		}
	   }
	   else
	   {
		if(flag==1)
			y = y + s2;
		else
		{
			x = x + s1;
			g = g + 2*dy;
		}
	   }
	   i++;
	   }
}
void DDA(int X1,int Y1,int X2,int Y2)                //implementetion of DDA algorithm
{
      int temp,dy,dx,i=1;
      float X,Y,xinc,yinc,steps;
      dx=X2-X1;
      dy=Y2-Y1;
      if(abs(dx)>=abs(dy))
	{
	steps = dx;
	}
      else
	{
	steps = dy;
	}
      xinc = (float)dx/steps;
      yinc = (float)dy/steps;
      X = X1;
      Y = Y1;
      putpixel(X,Y,3);
      while(i<=steps)
      {
	X = X + xinc;
	Y = Y + yinc;
	X1 = X + 0.5;
	Y1 = Y + 0.5;
	putpixel(X1,Y1,3);
	i++;
      }
getch();
}

void Object()                                                  //craeating a object
{
	int ch,temp=0;
	printf("\n\tEnter your choice\n\t");                            //asking for choice
     printf("\n\t1) triangle \n\t 2) HUT \n\t 3)Square \n\t 4) Exit ");    //accecepting a choice
     scanf("%d",&ch);
     while(temp==0)
     {
     switch(ch)
		{
		case 1:                                               //drawing a triangle using DDA algorithm
		     printf("\n A triangle is selected (DDA)");
		     DDA(100,100,150,300);
		     DDA(100,100,250,320);
		     DDA(150,300,250,320);
		     break;

		case 2:                                                //drawing a hut using Bresenham algorithm
			printf("\n A Hut is selected (DDA)");
			DDA(50,150,250,50);
			DDA(250,50,450,150);
			DDA(450,150,50,150);
			DDA(250,150,450,400);
			DDA(450,400,50,400);
			DDA(50,400,50,150);
			DDA(200,400,200,300);
			DDA(200,300,300,300);
			DDA(300,300,300,400);
			break;

		case 3:                                                          //dawing a square using DDA and Bresenham algorithm
			printf("\n A Square is selected (DDA And Bresenham)");
			 DDA(100,100,200,100);
			 DDA(200,100,200,200);
			 Bresenham(200,200,100,200);
			 Bresenham(100,200,100,100);
			 break;

		case 4:                   //EXIT
			temp=1;
			break;
		}
	}
}

int sign(int y)
{
if(y<0)
	return -1;
else if(y==0)
	return 0;
else
	return 1;
}














