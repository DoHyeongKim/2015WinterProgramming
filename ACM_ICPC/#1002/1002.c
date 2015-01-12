#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calAbsSum(int a, int b){
	return abs(a+b);
}

double calAbsAbb(int a, int b){
	return abs(a-b);
}

double distance(int x1, int y1, int x2, int y2){
	return sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
}

int makeJudge(int *coordA, int *coordB){
	double disCenter = distance(coordA[0], coordA[1], coordB[0], coordB[1]);
	double absSum = calAbsSum(coordA[2],coordB[2]);
	double absAbb = calAbsAbb(coordA[2],coordB[2]);

	if(disCenter == 0){
		if((coordA[2]==coordB[2])) return -1;
		else return 0;
	}else{
		if((absAbb<disCenter) && (disCenter<absSum)) return 2;
		else if((absAbb==disCenter)||(absSum==disCenter)) return 1;
		else if((absSum<disCenter)||(absAbb>disCenter)) return 0;
	}
}

int main(){
	int caseNum;
	int *answers;
	int i = 0;
	scanf("%d", &caseNum);
	int count = caseNum;
	answers = (int *)malloc(sizeof(int)*caseNum);

	int *input1 = (int *)malloc (sizeof(int)*3);
	int *input2 = (int *)malloc (sizeof(int)*3);

	while(count-->0){
		scanf("%d%d%d",input1,input1+1,input1+2); scanf("%d%d%d",input2,input2+1,input2+2);

		answers[i] = makeJudge(input1, input2);
		i++;
	}

	for(int j = 0; j<caseNum;j++){
		printf("%d\n",answers[j]);
	}
	free(answers);
	free(input1);
	free(input2);
	return 0;
}

