#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<alloc.h>
#include<graphics.h>
#pragma pack(1)

unsigned char huge Image_Data[640][640];

typedef struct
{
  char Type[2];    //File type "BM"
  unsigned long file_size;
  unsigned int imageDataOffset;
  unsigned long Width;
  unsigned long Height;
  unsigned short Reserved1;
  unsigned short Reserved2;
  unsigned long XPixelsPerMeter;
  unsigned long YPixelsPerMeter;
}bmp_header;


void main()
{
	FILE *file;
	bmp_header bh;

	int gd = DETECT, gm;
	struct palettetype palette;

	int i, y, j, k, error, Height, Width;

	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	error = graphresult();

	if (error != grOk)
	{
	   printf("Graphics error: %s\n", grapherrormsg(error));
	   exit(1);
	}

	//palette
	getpalette(&palette);

	clrscr();
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

	file = fopen("C:\\TURBOC3\\BIN\\zelda.bmp","rb");
	fread(&bh, sizeof(bmp_header), 1, file);

	if(bh.Type[0] != 'B' && bh.Type[1] != 'M')
	{
		printf("\nImage Chosen is not .bmp");
		return;
	}
	printf("\n Image Type : %c%c \n Image Size : %ld KB",bh.Type[0],bh.Type[1],bh.file_size/1024);
	printf("\n Image Width %ld \n Image Height : %ld ",bh.Width,bh.Height);

	fseek(file,bh.imageDataOffset,SEEK_SET);

	/* create gray scale */
	for (i=0; i<palette.size; i++)
	{
		setrgbpalette(palette.colors[i], i*4, i*4, i*4);
	}

	//girlface.bmp has Height and Width in this range
	Width=512;
	Height=512;

	for(i=0;i<Width;i++)
	{
		for(j=0;j<Height;j++)
		{
		   Image_Data[i][j]=fgetc(file);
		}
		if(i%4==0)
		{
			for(k=0;k<(i%4);k++)
			{
			      fgetc(file);
			}
		}
	}

	//display image
	for(i=0;i<Width;i++)
	{
		for(j=0;j<Height;j++)
		{
			putpixel(j,512-i,(Image_Data[i][j]/16));
		}
	}

	getch();

	//Vertical Flip
	for(i=0;i<Width;i++)
	{
		for(j=0;j<Height;j++)
		{
			putpixel(512-j,512-i,(Image_Data[i][j]/16));
		}
	}

	getch();

	//Horizontal Flip
	for(i=0;i<Width;i++)
	{
		for(j=0;j<Height;j++)
		{
			putpixel(j,i,(Image_Data[i][j]/16));
		}
	}

	getch();
}