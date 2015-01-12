#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "Selection_Sort.c"

int main(){
	int test[] = {4,2,3,1,5};
	int sizeTest = (sizeof(test))/(sizeof(test[1]));

	selection_Sort(test,sizeTest);

	for(int i = 0; i<sizeTest;i++){
		printf("%d,",*(test+i));
	}
}