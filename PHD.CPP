#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void main()
{
int gdriver = DETECT,gmode;
initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
line(10,10,620,10);
line(10,10,10,470);
line(620,10,620,470);
line(10,470,620,470);
outtextxy(300,20,"MENU");
line(40,40,305,40); //lefttop-----------
line(320,40,590,40);//righttop-----------
line(40,40,40,430);//leftleft |
line(40,430,305,430);//leftbottom---------
line(305,40,305,430);//leftright |
line(320,40,320,430);//rightleft |
line(320,430,590,430);//rightbottom-----------
line(590,40,590,430);//rightright |



getch();
closegraph();
}