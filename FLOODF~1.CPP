#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>

void floodfill(int, int, int, int);

int main()
{
	int gdriver = DETECT,gmode;
	initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
	rectangle(100,100,150,125);
	floodfill(125,112,15,0);
	getch();
}

void floodfill(int x, int y, int f_col, int prev_col)
{
 if (getpixel(x,y)==prev_col)
 {
 delay(1);
 putpixel(x, y, f_col);
 floodfill(x+1, y, f_col, prev_col);
 floodfill(x, y+1, f_col, prev_col);
 floodfill(x-1, y, f_col, prev_col);
 floodfill(x, y-1, f_col, prev_col);
 }
}
