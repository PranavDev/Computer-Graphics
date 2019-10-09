#include<conio.h>
#include<stdio.h>
#include<graphics.h>
void main()
{
int gd=0,n,x[10][3],r[10][3],r1[3][3],ga,xm,ym,i,j,k;
int m[3][3]={{0,1,0},{1,0,0},{0,0,1}};
int rx[3][3]={{1,0,0},{0,-1,0},{0,0,1}};
int rot[3][3]={{0,1,0},{-1,0,0},{0,0,1}};
initgraph(&gd,&ga,"C:\\Tc\\BGI");
xm=getmaxx();
ym=getmaxy();

printf("Enter the no. of vertices:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
for(j=0;j<2;j++)
{
printf("vertex [%d][%d]:",i,j);
scanf("%d",&x[i][j]);
}
x[i][j]=1;
}
cleardevice();
line(xm/2,0,xm/2,ym);
line(0,ym/2,xm,ym/2);
setviewport(xm/2,ym/2,xm,ym,0);

getch();
for(i=0;i<n-1;i++)
{

	line(x[i][0],x[i][1],x[i+1][0],x[i+1][1]);
}
line(x[0][0],x[0][1],x[i][0],x[i][1]);
getch();
printf("\tReflection about y=x");

for(k=0;k<3;k++)
{
	for(i=0;i<n;i++)
	{
	 r[i][k]=0;
		for(j=0;j<3;j++)
		{

			r[i][k]+=x[i][j]*m[j][k];
		}

	}
}
getch();
setcolor(5);
for(i=0;i<n-1;i++)
{

       line(r[i][0],r[i][1],r[i+1][0],r[i+1][1]);
}
line(r[0][0],r[0][1],r[i][0],r[i][1]);
getch();

printf("\n\treflection about x followed by counter clockwise rotation by 90");
for(k=0;k<3;k++)
{
	for(i=0;i<3;i++)
	{
		r1[i][k]=0;
		for(j=0;j<3;j++)
		{
			r1[i][k]+=rx[i][j]*rot[j][k];

		}

	}
}
for(k=0;k<3;k++)
{
	for(i=0;i<n;i++)
	{
	 r[i][k]=0;
		for(j=0;j<3;j++)
		{

			r[i][k]+=x[i][j]*r1[j][k];
		}

	}
}

setcolor(10);
for(i=0;i<n-1;i++)
{

       line(r[i][0],r[i][1],r[i+1][0],r[i+1][1]);
}
line(r[0][0],r[0][1],r[i][0],r[i][1]);

getch();
}