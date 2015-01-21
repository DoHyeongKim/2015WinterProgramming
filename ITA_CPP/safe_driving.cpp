#include <stdio.h>
//#include<conio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#define WIDTH 15
#define HEIGHT 24
#define WALL '%'
#define BLOCK '!'
#define ME '@'
#define OFTEN 8
#define SPEED 7000

void sleep(int t)
{
	for(int i=0;i<t;i++)
		for( int j=0;j<t;j++)
			;
}
int main()
{
	int hp = 10;
	int score = 0;
	int pos = 3;
	int i, j;
	int c;
	char map[HEIGHT][WIDTH] = {0};//{ {1}, {1,1}, {1,1,1}, {1,1,1,1} };


	while(hp>0)
	{
//		system("cls");
		if(kbhit())
		{
			c = getch();
			if(c=='z' && pos>1)
				pos--;
			else if(c=='x' && pos<WIDTH)
				pos++;
		}

		for(i=HEIGHT-1; i>0; i--)
			for(j=0; j<WIDTH; j++)
				map[i][j] = map[i-1][j];
		for(j=0; j<WIDTH; j++)
			if(rand()%10>OFTEN)
				map[0][j] = 1;
			else
				map[0][j] = 0;

		if(map[HEIGHT-1][pos-1]==1)
		{
			hp--;
			sleep(SPEED*3);
		}

		for(i=0; i<HEIGHT-1; i++)
		{
			putch(WALL);
			for(j=0; j<WIDTH; j++)
				if(map[i][j]==1)
					putch(BLOCK);
				else
					putch(' ');
			putch(WALL);
			if(i==0)
				printf("\t\t HP: %d", hp);
			else if(i==1)
				printf("\t\t SCORE: %d", score);
			putch('\n');
		}
		putch(WALL);
		for(j=1; j<pos; j++)
			putch(' ');
		putch(ME);
		for(j=pos+1; j<=WIDTH; j++)
			putch(' ');
		putch(WALL);
		putch('\n');
		sleep(SPEED);
		score += 100;
	}

	printf("Game over!!! Your score is %d!!!\n", score);
	printf("Press enter\n");

	while(1)
	{
		c = getch();
		if(c==13)
			break;
	}
	return 0;
}