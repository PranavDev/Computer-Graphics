#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void main()
{
int gdriver = DETECT,gmode;
clrscr();
initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
printf("\t\t\t\tBar Graph");
outtextxy(500,450,"X Axis ->");
line(25,420,600,420);
line(30,417,600,417);
outtextxy(0,425,"O");
outtextxy(60,425,"10");
outtextxy(110,425,"20");
outtextxy(165,425,"30");
outtextxy(215,425,"40");
outtextxy(265,425,"50");
outtextxy(0,20,"Y Axis");
line(30,50,30,425);
outtextxy(10,350,"10-");
outtextxy(10,300,"20-");
outtextxy(10,250,"30-");
outtextxy(10,200,"40-");
outtextxy(10,150,"50-");
outtextxy(10,100,"60-");
outtextxy(10,50,"70-");
setfillstyle(3,5);
bar3d(50,300,80,420,5,5);
setfillstyle(3,5);
bar3d(100,200,130,420,5,5);
setfillstyle(3,5);
bar3d(150,150,180,420,5,5);
setfillstyle(3,5);
bar3d(200,250,230,420,5,5);
setfillstyle(3,5);
bar3d(250,350,280,420,5,5);
getch();
closegraph();
}