#include <stdio.h>
#include <stdlib.h>

int calculateNum(int a, int b){
	if((a==0)&&(b==0)) return 1;
	else{
		int temp = a;

		for(int i = 0; i<b-1;i++){
			temp = (temp * a)%10;
		}

		return temp;
	}
}

int main(){
	int numCase;
	int *store = (int *)malloc(sizeof(int)*numCase);
	scanf("%d", &numCase);
	int count = numCase;
	int i = 0;

	while(count-->0){
		int a,b;
		scanf("%d%d", &a,&b);
		store[i] = calculateNum(a,b);
		i++;
	}
	for(int i = 0; i<numCase;i++){
		printf("%d\n",store[i]);
	}
}

// 1 step, consider only one digit
// 2 step, consider repetitive range of digits.