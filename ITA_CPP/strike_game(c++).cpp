#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

class Player;

class Solution{
	int num[3];
	int strike;
	int ball;
public:
	Solution();
	bool confirm(Player& p);
	void show_result();
};
class Player{
	int num[3];
public:
	void input();
	int get(int i) { return num[i]; }
};

Solution::Solution() : strike(0), ball(0)
{
	srand(time(NULL));
	do
	{
		num[0] = rand()%10;
		num[1] = rand()%10;
		num[2] = rand()%10;
	}while(num[0]==num[1] || num[0]==num[2] || num[1]==num[2]);	
}
bool Solution::confirm( Player& p )
{
	strike = ball = 0;
	for(int i=0; i<3; i++)
	{ 
		if(num[i] == p.get(i))
			strike++;
		else
		{
			for(int j=0; j<3; j++)
				if(num[j] == p.get(i))
					ball++;
		}
	}
	if(strike==3)
		return true;
	else 
		return false;
}
void Solution::show_result()
{
	cout<<strike<<"strike, "<<ball<<"ball"<<endl;
}


void Player::input()
{
	cout<<"세개의 숫자를 입력하세요 : ";
	cin>>num[0]>>num[1]>>num[2];
}

void main()
{
	Solution s;
	Player p;
	bool t;
	do
	{
		p.input();
		t = s.confirm(p);
		s.show_result();
	}while(t==false);
}