#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<stdio.h>

void koch(int x1, int y1, int x2, int y2, int cnt)
{
	float angle = 60*M_PI/180;
 	int x3 = (2*x1+x2)/3;
 	int y3 = (2*y1+y2)/3;

	int x4 = (x1+2*x2)/3;
 	int y4 = (y1+2*y2)/3;

 	int x = x3 + ((x4-x3)*cos(angle))+((y4-y3)*sin(angle));
  	int y = y3 - ((x4-x3)*sin(angle))+((y4-y3)*cos(angle));

 	if(cnt>0)
 	{
  		koch(x1, y1, x3, y3, cnt-1);
  		koch(x3, y3, x, y, cnt-1);
  		koch(x, y, x4, y4, cnt-1);
  		koch(x4, y4, x2, y2, cnt-1);
 	}
 	else
 	{
  		line(x1, y1, x3, y3);
  		line(x3, y3, x, y);
		line(x, y, x4, y4);
		line(x4, y4, x2, y2);
	}
}

void main()
{
	int gdriver = DETECT, gmode;
	initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
	int x1, y1, x2, y2, N;
	printf("Enter the starting co-ordinates of Koch curve : ");
	scanf("%d %d", &x1, &y1);
	printf("Enter the ending co-ordinates of Koch curve : ");
	scanf("%d %d", &x2, &y2);
	printf("\nEnter the Order : ");
	scanf("%d",&N);

	putpixel(x1,y1,14);
	putpixel(x2,y2,14);
	getch();
	koch(x1, y1, x2, y2, N);
	getch();
}

