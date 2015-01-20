
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
	int i=0, j=-1;    //ù������ġ
	int new_dist, dist;

	cout<<"Input size of snail array : ";
	cin>>length;

	max = length*length;
	arr = new int [max];

	dist = new_dist = length;
	for(int k=0; k < max; )
	{
		switch(direction)  //���⿡���� �Ѱ��� ���ư���
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
		arr[ length*i + j ] = ++k;   //arr[ length*i + j ]�� ������ ��ġ�� �ȴ�.
								   //�Ѱ��� �Űܰ� ��ġ�� �̵����� k�� �Է��Ѵ�.

		dist--;        //dist�� ������⿡�� ������ �Ÿ��� ��Ÿ���� ����
					   //�Ѱ��� �̵��Ͽ����Ƿ� ������ �Ÿ��� 1�پ���.

		if(dist==0)       //���� ������ �Ÿ��� 0�̶�� ������ ��ģ��.
		{
			if(direction==RIGHT || direction==LEFT)
			{
				new_dist--;     //new_dist�� ������ �ٲ����� ������ �Ÿ��� ��Ÿ���� ����
				dist = new_dist;
			}
			else
				dist = new_dist;

			direction = (direction+1)%4; //������ ��ġ�� �κ� : RIGHT->DOWN->LEFT->UP->RIGHT
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

	cout<<"�����̹迭�� ũ�⸦ �Է��ϼ��� : ";
	cin>>length;

	arr = new int [length*length];
//
// �� �κп� �����Ϲ迭 arr �� ������ ���� �Ҵ����ּ���^^
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
