#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>

void main()
{
	int x,y,r,xmin,ymin,xmax,ymax;
	int gm,gd=DETECT;
	initgraph(&gd,&gm,"C:/TurboC3/BGI");
	xmin=100;
	ymin=100;
	xmax=400;
	ymax=400;
	rectangle(xmin,ymin,xmax,ymax);
	x=110;
	y=395;
	r=5;
	circle(x,y,r);
	while(1)
	{
		while((x+r)<xmax && (y-r)>ymin)
		{
			setcolor(RED);
			cleardevice();
			rectangle(xmin,ymin,xmax,ymax);
			x = x+(r*cos(5));
			y--;
			circle(x,y,r);
			delay(5);
		}

		while((x-r)>xmin && (y-r)>ymin)
		{
			setcolor(YELLOW);
			cleardevice();
			rectangle(xmin,ymin,xmax,ymax);
			x = x-(r*cos(5));
			y--;
			circle(x,y,r);
			delay(5);
		}
			
		while((x+r)<xmax && (y+r)<ymax)
		{
			setcolor(GREEN);
			cleardevice();
			rectangle(xmin,ymin,xmax,ymax);
			x = x+(r*cos(5));
			y++;
			circle(x,y,r);
			delay(5);
		}
			
		while((x-r)>xmin && (y+r)<ymax)
		{
			setcolor(BLUE);
			cleardevice();
			rectangle(xmin,ymin,xmax,ymax);
			x = x-(r*cos(5));
			y++;
			circle(x,y,r);
			delay(5);
		}
	}
}
