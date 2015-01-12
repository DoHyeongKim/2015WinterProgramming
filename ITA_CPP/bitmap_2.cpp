#include<stdio.h>

//http://jae02.tistory.com/40 강의시 참고!!

#define WHITE ' '
#define BLACK 'r'

void main()
{
	FILE* bmpf = fopen("12x12.bmp","rb");
	FILE* txtf = fopen("sample.txt","wt");
	if( bmpf==NULL || txtf==NULL )
	{
		puts("file open failed!");
		return;
	}
				
	int width;
	int height;
	short bit_count;
	int size_image;
	fseek( bmpf, 18, SEEK_SET );
	fread( &width, 4, 1, bmpf );
	fread( &height, 4, 1, bmpf );
	fseek( bmpf, 2, SEEK_CUR );
	fread( &bit_count, 2, 1, bmpf );
	fseek( bmpf, 4, SEEK_CUR );
	fread( &size_image, 4, 1, bmpf );

	if(bit_count!=24)
	{
		puts("지원하지 않는 파일형식입니다!");
		return;
	}

	fseek( bmpf, 16, SEEK_CUR );
	unsigned char* buff = new unsigned char[size_image];
	fread((void*)buff, 1, size_image, bmpf);

	int i, j;
	int space = 0;
	if(width%4!=0)
		space = 4 - width%4;
	int k = (width+space)*(height-1)*3;

	for(i=0; i<height; i++)
	{
		for(j=0; j<width; j++)
		{
			if(buff[k] == 0xff)
				fputc(WHITE, txtf);
			else
				fputc(BLACK, txtf);
			k += 3;
		}
		k += space*3;
		k -= (width+space)*6;
		fputc('\n', txtf);
	}

	fclose(txtf);
	fclose(bmpf);

}