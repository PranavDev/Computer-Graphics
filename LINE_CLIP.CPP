#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>

void main()
{
	int gm ,gd=DETECT,i, x1, y1, x2, y2, xf1, yf1, xf2, yf2, xf3, yf3, xf4, yf4;
	int x3, y3, x4, y4;                     	//final co-ordinates of clipped line
	int code1[4], code2[4], res[4], ch;		//code1 and code2 are opcodes of 2 points of the line. Res[4] is the array of AND of code1 and code2.
	float m;

	for(i=0; i<4; i++)
	{
		code1[i] = 0;		//initialise to 0.
		code2[i] = 0;
	}
	initgraph(&gd, &gm, "c:\\tc/BGI");
	printf("Enter the co-ordinates of starting point of line : ");
	scanf("%d%d", &x1, &y1);
	printf("Enter the co-ordinates of ending point of line : ");
	scanf("%d%d", &x2, &y2);
	printf("Enter the co-ordinates of rectangular frame : ");
	scanf("%d%d%d%d%d%d%d%d", &xf1, &yf1, &xf2, &yf2, &xf3, &yf3, &xf4, &yf4);
	
	//Drawing frame and line.
	setcolor(WHITE);
	line(xf1, yf1, xf2, yf2);
	line(xf2, yf2, xf3, yf3);
	line(xf3, yf3, xf4, yf4);
	line(xf4, yf4, xf1, yf1);
	setcolor(RED);
	line(x1, y1, x2, y2);
	getch();
	
	//Assigning outcode.
	if(x1<xf1)
		code1[3] = 1;
	else if(x1>xf2)
		code1[2] = 1;
	if(x2<xf1)
		code2[3] = 1;
	else if(x2>xf2)
		code2[2] = 1;

	if(y1<yf1)
		code1[0] = 1;
	else if(y1>yf3)
		code1[1] = 1;
	if(y2<yf1)
		code2[0] = 1;
	else if(y2>yf3)
		code2[1] = 1;

	for(i=0; i<4; i++)
	{
		if(code1[i]==code2[i])
		{
			if(code1[i]==0)
				res[i] = 0;
			else
				res[i] = 1;
		}
		else
		{
			res[i] = 0;
		}
	}

	for(i=0; i<4; i++)
	{
		if(res[i]!=0)
		{
			printf("\nLine lies outside the frame !\n");
			getch();
			exit(0);
		}
	}

	//If res[] is 0
	for(i=0; i<4; i++)
	{
		if(code1[i]!=0 || code2[i]!=0)
		{
			break;
		}
	 }
	if(i==4)				//Line lies completely inside.
	{
		setcolor(YELLOW);
		line(x1, y1, x2, y2);
		getch();
		exit(0);
	}

	for(i=3; i>=0; i--)
	{
		if(code1[i]!=0)	//only check code1 i.e. starting co-ordinate
			break;
	}

	m = (1.0) * (y2-y1) / (x2-x1);
	ch = i;
	if(i==-1)			//Condition if point lies inside.
		ch = 4;
	switch(ch)
	{
		case 4:
			x3 = x1;
			y3 = y1;
			break;
		case 3:				//To the left
			if(code1[0]==0 && code1[1]==0)		//Check if it lies to the left, left above or left below.
			{
				x3 = xf1;
				y3 = (m * (x3-x1)) + y1;
			}
			else if(code1[0]==1)			//Lies to left above.
			{
				x3 = xf1;
				y3 = (m * (x3-x1)) + y1;
				if(y3<yf1)			//Intersects top edge of window.
				{
					y3 = yf1;
					x3 = ((y3-y1) / m) + x1;
				}
				else if(y3>yf1 && y3<yf4)		//Intersects to the left of window.
				{
					x3 = xf1;
					y3 = (m * (x3-x1)) + y1;
				}
				else if(y3==yf1)			//Intersects the left above vertex.
				{
					x3 = xf1;
				}
			}
			else if(code1[1]==1)			//Lies to left below.
			{
				x3 = xf1;
				y3 = (m * (x3-x1)) + y1;
				if(y3>yf4)
				{
					y3 = yf4;
					x3 = ((y3-y1) / m) + x1;
				}
				else if(y3>yf1 && y3<yf4)
				{
					x3 = xf1;
					y3 = (m * (x3-x1)) + y1;
				}
				else if(y3==yf4)
				{
					x3 = xf1;
				}
			}
			break;
		case 2:						//Lie to right,right above or right below.
			if(code1[0]==0 && code1[1]==0)
			{
				x3 = xf2;
				y3 = (m * (x3-x1)) + y1;
			}
			else if(code1[0]==1)
			{
				x3 = xf2;
				y3 = (m * (x3-x1)) + y1;
				if(y3<yf1)
				{
					y3 = yf1;
					x3 = ((y3-y1) / m) + x1;
				}
				else if(y3>yf1 && y3<yf4)
				{
					x3 = xf1;
					y3 = (m * (x3-x1)) + y1;
				}
				else if(y3==yf1)
				{
					x3 = xf2;
				}
			}
			else if(code1[1]==1)
			{
				x3 = xf2;
				y3 = (m * (x3-x1)) + y1;
				if(y3>yf4)
				{
					y3 = yf4;
					x3 = ((y3-y1) / m) + x1;
				}
				else if(y3>yf1 && y3<yf4)
				{
					x3 = xf2;
					y3 = (m * (x3-x1)) + y1;
				}
				else if(y3==yf4)
				{
					x3 = xf2;
				}
			}
			break;
		case 1:					//Lies below the window.
			y3 = yf3;
			x3 = ((y3-y1) / m) + x1;
			break;
		case 0:
			y3 = yf1;
			x3 = ((y3-y1) / m) + x1;
			break;
	}
	//Checking for second point.
	for(i=3; i>=0; i--)
	{
		if(code2[i]!=0)	//only check code2 i.e. ending co-ordinate
			break;
	}

	m = (1.0) * (y2-y1) / (x2-x1);
	ch = i;
	if(i==-1)
		ch = 4;
	switch(ch)
	{
		case 4:
			x4 = x2;
			y4 = y2;
			break;
		case 3:
			if(code2[0]==0 && code2[1]==0)
			{
				x4 = xf1;
				y4 = (m * (x4-x2)) + y2;
			}
			else if(code2[0]==1)
			{
				x4 = xf1;
				y4 = (m * (x4-x2)) + y2;
				if(y4<yf1)
				{
					y4 = yf1;
					x4 = ((y4-y2) / m) + x2;
				}
				else if(y4>yf1 && y4<yf4)
				{
					x4 = xf1;
					y4 = (m * (x4-x2)) + y2;
				}
				else if(y4==yf1)
				{
					x4 = xf1;
				}
			}
			else if(code2[1]==1)
			{
				x4 = xf1;
				y4 = (m * (x4-x2)) + y2;
				if(y4>yf4)
				{
					y4 = yf4;
					x4 = ((y4-y2) / m) + x2;
				}
				else if(y4>yf1 && y4<yf4)
				{
					x4 = xf1;
					y4 = (m * (x4-x2)) + y2;
				}
				else if(y4==yf4)
				{
					x4 = xf1;
				}
			}
			break;
		case 2:
			if(code2[0]==0 && code2[1]==0)
			{
				x4 = xf2;
				y4 = (m * (x4-x2)) + y2;
			}
			else if(code2[0]==1)
			{
				x4 = xf2;
				y4 = (m * (x4-x2)) + y2;
				if(y4<yf1)
				{
					y4 = yf1;
					x4 = ((y4-y2) / m) + x2;
				}
				else if(y4>yf1 && y4<yf4)
				{
					x4 = xf1;
					y4 = (m * (x4-x2)) + y2;
				}
				else if(y4==yf1)
				{
					x4 = xf2;
				}
			}
			else if(code2[1]==1)
			{
				x4 = xf2;
				y4 = (m * (x4-x2)) + y2;
				if(y4>yf4)
				{
					y4 = yf4;
					x4 = ((y4-y2) / m) + x2;
				}
				else if(y4>yf1 && y4<yf4)
				{
					x4 = xf2;
					y4 = (m * (x4-x2)) + y2;
				}
				else if(y4==yf4)
				{
					x4 = xf2;
				}
			}
			break;
		case 1:
			y4 = yf3;
			x4 = ((y4-y2) / m) + x2;
			break;
		case 0:
			y4 = yf1;
			x4 = ((y4-y2) / m) + x2;
			break;
	}

	setcolor(YELLOW);
	line(x3, y3, x4, y4);
	getch();
	closegraph();
}


