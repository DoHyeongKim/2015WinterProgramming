#include <iostream>
#include <cmath>
using namespace std;

double distance(int x1, int y1, int x2, int y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

double addNum(int x, int y){
	return x+y;
}

double absAbb(int x, int y){
	return abs(x-y);
}

int makeJudge(int *coordA, int *coordB){
	double disCenter = distance(coordA[0], coordA[1], coordB[0], coordB[1]);
	double addRad = addNum(coordA[2], coordB[2]);
	double abbRad = absAbb(coordA[2], coordB[2]);

	if(disCenter==0){
		if(coordA[2]==coordB[2]) return -1;
		else return 0;
	}else{
		if((abbRad<disCenter)&&(disCenter<addRad)) return 2;
		else if((abbRad==disCenter)||(addRad==disCenter)) return 1;
		else if((addRad<disCenter)||(addRad>disCenter)) return 0;
	}
}

int main(){
	int inputNum;
	cin >> inputNum;
	int count = inputNum;
	int i = 0;

	int *store = new int[inputNum]; // delete: free

	int *inputA = new int[3];
	int *inputB = new int[3];

	while(count-->0){
		cin >> *(inputA) >> *(inputA+1) >> *(inputA+2);
		cin >> *(inputB) >> *(inputB+1) >> *(inputB+2);
		
		store[i] = makeJudge(inputA,inputB);
		i++;
	}
	for(int i = 0; i<inputNum;i++){
		cout << store[i] << endl;
	}
	delete store;
	delete inputA;
	delete inputB;
}