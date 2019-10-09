#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>

struct bmpHeader
{
    char type1;
    char type2;
    long size;
    short reserved1;
    short reserved2;
    long offBits;
    long bSize;
    long bWidth;
    long bHeight;
    short bPlanes;
    short bBitCount;
    long bCompression;
    long bSizeImage;
    long bXPix;
    long bYPix;
    long bClrUsed;
    long bClrImp;
}bmp;

int main()
{
	int gd = DETECT, gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

	FILE *fp = fopen("lena.bmp","rb");

	if(fp==NULL)
	{
	    printf("Problem\n");
	    return 1;
	}


	fread(&bmp.type1,1,1,fp);
	fread(&bmp.type2,1,1,fp);
	fread(&bmp.size,4,1,fp);
	fread(&bmp.reserved1,2,1,fp);
	fread(&bmp.reserved2,2,1,fp);
	fread(&bmp.offBits,4,1,fp);
	fread(&bmp.bSize,4,1,fp);
	fread(&bmp.bWidth,4,1,fp);
	fread(&bmp.bHeight,4,1,fp);
	fread(&bmp.bPlanes,2,1,fp);
	fread(&bmp.bBitCount,2,1,fp);
	fread(&bmp.bCompression,4,1,fp);
	fread(&bmp.bSizeImage,4,1,fp);
	fread(&bmp.bXPix,4,1,fp);
	fread(&bmp.bYPix,4,1,fp);
	fread(&bmp.bClrUsed,4,1,fp);
	fread(&bmp.bClrImp,4,1,fp);

	printf("\nType : %c%c",bmp.type1,bmp.type2);
	printf("\nSize : %ld",bmp.size);
	printf("\nReserved1 : %hd",bmp.reserved1);
	printf("\nReserved2 : %hd",bmp.reserved2);
	printf("\nOffset Bits : %ld",bmp.offBits);
	printf("\nbiSize : %ld",bmp.bSize);
	printf("\nWidth : %ld",bmp.bWidth);
	printf("\nHeight : %ld",bmp.bHeight);
	printf("\nbiPlanes %hd",bmp.bPlanes);
	printf("\nbiBitCount : %hd",bmp.bBitCount);
	printf("\nbiCompression : %ld",bmp.bCompression);
	printf("\nbiSizeImage : %ld",bmp.bSizeImage);
	printf("\nbiXPixels/meter : %ld",bmp.bXPix);
	printf("\nbiYPixels/meter : %ld",bmp.bYPix);
	printf("\nbiClrUsed : %ld",bmp.bClrUsed);
	printf("\nbiClrImportant : %ld",bmp.bClrImp);

	fclose(fp);
	getch();
}
