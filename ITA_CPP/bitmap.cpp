#include<stdio.h>
#include<windows.h>

/*
http://jae02.tistory.com/40 강의시 참고!!

typedef struct tagBITMAPFILEHEADER {
        WORD    bfType;
        DWORD   bfSize;
        WORD    bfReserved1;
        WORD    bfReserved2;
        DWORD   bfOffBits;
} BITMAPFILEHEADER, FAR *LPBITMAPFILEHEADER, *PBITMAPFILEHEADER;
총 14바이트
 typedef struct tagBITMAPINFOHEADER{
        DWORD      biSize;
        LONG       biWidth;
        LONG       biHeight;
        WORD       biPlanes;
        WORD       biBitCount;
        DWORD      biCompression;
        DWORD      biSizeImage;
        LONG       biXPelsPerMeter;
        LONG       biYPelsPerMeter;
        DWORD      biClrUsed;
        DWORD      biClrImportant;
} BITMAPINFOHEADER, FAR *LPBITMAPINFOHEADER, *PBITMAPINFOHEADER;
총 40바이트
*/
#define WHITE ' '
#define BLACK 'r'

void main()
{
	BITMAPFILEHEADER a;
	BITMAPINFOHEADER b;
	FILE* bmpf = fopen("sample3.bmp","rb");
	FILE* txtf = fopen("sample3_3.txt","wt");
	if( bmpf==NULL || txtf==NULL )
	{
		puts("file open failed!");
		return;
	}
														//http://jae02.tistory.com/40
	fread((void*)&a, sizeof(BITMAPFILEHEADER), 1, bmpf);
	fread((void*)&b, sizeof(BITMAPINFOHEADER), 1, bmpf);

	if(b.biBitCount!=24)
	{
		puts("지원하지 않는 파일형식입니다!");
		return;
	}

	unsigned char* buff = new unsigned char[b.biSizeImage];
	fread((void*)buff, 1, b.biSizeImage, bmpf);

//	unsigned char buff[1000];
//	fread((void*)buff, 1, sizeof(buff), bmpf);
	int i, j;
	int space = 0;
	if(b.biWidth%4!=0)
		space = 4 - b.biWidth%4;
	int k = (b.biWidth+space)*(b.biHeight-1)*3;

	for(i=0; i<b.biHeight; i++)
	{
		for(j=0; j<b.biWidth; j++)
		{
			if(buff[k] == 0xff)
				fputc(WHITE, txtf);
			else
				fputc(BLACK, txtf);
			k += 3;
		}
		k += space*3;
		k -= (b.biWidth+space)*6;
		fputc('\n', txtf);
	}

	fclose(txtf);
	fclose(bmpf);

}