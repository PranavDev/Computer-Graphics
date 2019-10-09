#include <iostream.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>


float lx=100,ly=100;
void drawl(int,int);
void hilbert(int,int,int);

int main()
{
    int gdriver = DETECT,gmode;
    initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
    
    int dx=10,dy=0,depth;
    
    cout<<"Enter the Depth : ";
    cin>>depth;
    
    hilbert(depth,dx,dy);
    getch();
    closegraph();
}

void hilbert(int depth,int dx,int dy)
{
    if(depth>1)
    {
        hilbert(depth-1,dy,dx);
    }
    drawl(dx,dy);

    if(depth>1)
    {
        hilbert(depth-1,dx,dy);
    }
    drawl(dy,dx);

    if(depth>1)
    {
        hilbert(depth-1,dx,dy);
    }
    drawl(-dx,-dy);

    if(depth>1)
    {
        hilbert(depth-1,-dy,-dx);
    }
    delay(50);
}

void drawl(int dy,int dx)
{
    line(lx,ly,lx+dx,ly+dy);
    lx = lx + dx;
    ly = ly + dy;
}
