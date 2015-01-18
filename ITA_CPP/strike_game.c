// strike game.cpp : Defines the entry point for the console application.
//


#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int main()
{
	int sol[3];
	int in[3];
	int strike;
	int ball;

	srand(time(NULL));
	do
	{
		sol[0] = rand()%10;
		sol[1] = rand()%10;
		sol[2] = rand()%10;
	}while(sol[0]==sol[1] || sol[0]==sol[2] || sol[1]==sol[2]);

	while(1)
	{
		printf("Input 3 integers : ");
		scanf("%d", &in[0]);
		scanf("%d", &in[1]);
		scanf("%d", &in[2]);\

		strike = ball = 0;
		for(int i=0; i<3; i++)
		{
			if(sol[i] == in [i])
				strike++;
			else
			{
				for(int j=0; j<3; j++)
					if(sol[j] == in[i])
						ball++;
			}
		}
		printf("%d strike,  %d ball \n",strike, ball);
		if(strike==3)
			break;
	}
return 0;
}

