
#include <iostream>
using namespace std;

#define RIGHT 0
#define DOWN 1
#define LEFT 2
#define UP 3


int main()
{
	int length, max;
	int direction = RIGHT;
	int* arr;
	int i=0, j=-1;    //첫시작위치
	int new_dist, dist;

	cout<<"Input size of snail array : ";
	cin>>length;

	max = length*length;
	arr = new int [max];

	dist = new_dist = length;
	for(int k=0; k < max; )
	{
		switch(direction)  //방향에따라 한걸음 나아간다
		{
		case RIGHT:
			j++;
			break;
		case DOWN:
			i++;
			break;
		case LEFT:
			j--;
			break;
		case UP:
			i--;
			break;
		}
		arr[ length*i + j ] = ++k;   //arr[ length*i + j ]는 현재의 위치가 된다.
								   //한걸음 옮겨간 위치에 이동걸음 k를 입력한다.

		dist--;        //dist는 현재방향에서 벽과의 거리를 나타내는 변수
					   //한걸음 이동하였으므로 벽과리 거리가 1줄었다.

		if(dist==0)       //만약 벽과의 거리가 0이라면 방향을 고친다.
		{
			if(direction==RIGHT || direction==LEFT)
			{
				new_dist--;     //new_dist는 방향을 바꾼후의 벽과의 거리를 나타내는 변수
				dist = new_dist;
			}
			else
				dist = new_dist;

			direction = (direction+1)%4; //방향을 고치는 부분 : RIGHT->DOWN->LEFT->UP->RIGHT
		}

	}

	for(i=0; i<length; i++)
	{
		for(j=0; j<length; j++)
		{
			cout<< arr[ length*i + j ] << ' ';
		}
		cout<<endl;
	}


	return 0;
}

/*
int main()
{
	int length;
	int* arr;

	cout<<"달팽이배열의 크기를 입력하세요 : ";
	cin>>length;

	arr = new int [length*length];
//
// 이 부분에 달팽일배열 arr 에 적절한 값을 할당해주세요^^
//
	for(int i=0; i<length; i++)
	{
		for(int j=0; j<length; j++)
		{
			cout<< arr[ length*i + j ] << ' ';
		}
		cout<<endl;
	}


	return 0;
}
*/
