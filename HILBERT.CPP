#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>

int xmin,ymin,xmax,ymax;

void drawp()
{
	line(xmin,ymin,xmin,ymax);
	line(xmin,ymax,xmax,ymax);
	line(xmax,ymax,xmax,ymin);
	line(xmax,ymin,xmin,ymin);
}

void order1(int x1, int y1, int x2, int y2, int r, int c)
{
	int a[4][2],p,q;
	p=abs(x2-x1);
	q=abs(y2-y1);

	a[0][0]=x1+(p/4);
	a[0][1]=y2-(q/4);
	a[1][0]=x1+(p/4);
	a[1][1]=y1+(q/4);
	a[2][0]=x2-(p/4);
	a[2][1]=y1+(q/4);
	a[3][0]=x2-(p/4);
	a[3][1]=y2-(q/4);

	if(r==0)
	{
		for(p=0;p<3;p++)
			line(a[p][0],a[p][1],a[p+1][0],a[p+1][1]);
	}
	else
	{
		line(a[0][0],a[0][1],a[1][0],a[1][1]);
		line(a[3][0],a[3][1],a[0][0],a[0][1]);
		line(a[3][0],a[3][1],a[2][0],a[2][1]);
	}

	if(c==0)
	{
		line(a[0][0],a[0][1],a[0][0],y2);
		line(a[3][0],a[3][1],a[3][0],y2);
	}
	else if(c==1)
	{
		line(a[0][0],a[0][1],a[0][0],y2);
		line(a[3][0],a[3][1],x2,a[3][1]);
	}
	else if(c==2)
	{
		line(a[0][0],a[0][1],x1,a[0][1]);
		line(a[3][0],a[3][1],x2,a[3][1]);
	}
	else if(c==3)
	{
		line(a[1][0],a[1][1],a[1][0],y1);
		line(a[2][0],a[2][1],x2,a[2][1]);
	}
	else if(c==4)
	{
		line(a[1][0],a[1][1],x1,a[1][1]);
		line(a[2][0],a[2][1],x2,a[2][1]);
	}
}

void order2(int x1, int y1, int x2, int y2)
{
	int xc,yc;
	xc=x1+(x2-x1)/2;
	yc=y1+(y2-y1)/2;
	order1(x1,y1,xc,yc,0,1);
	order1(xc,y1,x2,yc,0,2);
	order1(x1,yc,xc,y2,1,3);
	order1(xc,yc,x2,y2,1,4);
}

void order3(int p1,int q1,int p2,int q2)
{
	int xc1,yc1,p,q;
	cleardevice();
	drawp();
	xc1=p1+(xmax-xmin)/2;
	yc1=q1+(ymax-ymin)/2;

	order2(p1,q1,xc1,yc1);
	order2(xc1,q1,p2,yc1);
	order2(p1,yc1,xc1,q2);
	order2(xc1,yc1,p2,q2);

	p=(xmax-xmin)/2;
	q=(xmax-xmin)/2;

	line(p2-(7*p/8),q1+(3*q/8),xc1,q1+(3*q/8));
	line(p2-(7*p/8),q1+(5*q/8),xc1,q1+(5*q/8));
	line(p2-(p/8),q1+(3*q/8),p2-(p/8),q1+(5*q/8));
	line(p2-(p/8),q1+(7*q/8),p2-(p/8),q1+(9*q/8));
	line(p2-(3*p/8),q1+(7*q/8),p2-(3*p/8),q1+(9*q/8));
	line(p2-(7*p/8),q2-(3*q/8),xc1,q2-(3*q/8));
	line(p2-(7*p/8),q2-(5*q/8),xc1,q2-(5*q/8));

	setcolor(0);
	line(p2-(7*p/8)-1,q1+(3*p/8),p2-(7*p/8)-1,q1+(5*p/8));
	line(p2-(7*p/8)-1,q2-(3*p/8),p2-(7*p/8)-1,q2-(5*p/8));
	line(p2-(p/8),q1+(7*p/8)+1,p2-(3*p/8),q1+(7*p/8)+1);
	line(p2-(p/8),q2-(7*p/8)-1,p2-(3*p/8),q2-(7*p/8)-1);
	line(p2-(p/8),q1+(3*p/8)+1,p2,q1+(3*p/8)+1);
	line(p2-(p/8),q1+(5*p/8),p2,q1+(5*p/8));
}


void main()
{
	int gd=DETECT,gm;
	int p,q;
	xmin=ymin=100;
	xmax=ymax=400;
	initgraph(&gd,&gm,"C:/TurboC3/BGI");
	drawp();
	order1(xmin,ymin,xmax,ymax,0,0);
	getch();

	cleardevice();
	drawp();
	order2(xmin,ymin,xmax,ymax);
	getch();

	cleardevice();
	drawp();
	order3(xmin,ymin,xmax,ymax);
	getch();
}



