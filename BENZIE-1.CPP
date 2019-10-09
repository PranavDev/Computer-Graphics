#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<stdio.h>

float tx[50], ty[50], midx[50], midy[50], nom=0;
float x[50], y[50];
void mid(int);
void swap(int);

void cal_init_mid()
{
 	nom = 5;
 	midx[0] = x[0];
 	midy[0] = y[0];
 	midx[1] = (x[0]+x[1])/2;
 	midy[1] = (y[0]+y[1])/2;
 	midx[2] = (x[1]+x[2])/2;
 	midy[2] = (y[1]+y[2])/2;
 	midx[3] = (x[2]+x[3])/2;
 	midy[3] = (y[2]+y[3])/2;
 	midx[4] = x[3];
 	midy[4] = y[3];
}	

void draw_lines(int n)
{
	for(int i=0; i<n-1; i++)
	{
   		line(midx[i],midy[i],midx[i+1],midy[i+1]);
 	}
}

void mid(int n)
{
	for(int i=0; i<n-1; i++)
	{
  		tx[i]=(midx[i]+midx[i+1])/2;
  		ty[i]=(midy[i]+midy[i+1])/2;
	}
 	swap(n);
}

void swap(int n)
{
	midx[0] = x[0];
	midy[0] = y[0];
 	
	for(int i=0; i<n-1; i++)
	{
 		midx[i+1]=tx[i];
 		midy[i+1]=ty[i];
 	}
 	midx[i+1] = x[3];
 	midy[i+1] = y[3];
 	draw_lines(n+1);
}

void main()
{
	int gd=DETECT, gm, n=0, it=0;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	cout<<"Enter n : ";
	cin>>n;
	cout<<"Enter the co-ordinates : ";
	for(int i=0; i<n; i++)
		cin>>x[i]>>y[i];

	for(i=0; i<n-1; i++)
		line(x[i],y[i],x[i+1],y[i+1]);

	line(x[i],y[i],x[0],y[0]);
	setcolor(BLUE);
	cal_init_mid();
	draw_lines(nom);  //nom = 5 initially
	getch();

	//iterations = 20
	it = 40;
	for(i=0;i<it;i++)
	{
		if(i==it-1)
	   		setcolor(RED);
	  	mid(i+5);
	}
	getch();
	closegraph();
}