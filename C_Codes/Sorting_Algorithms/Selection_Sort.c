#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "Selection_Sort.h"
#define MAX_NUM 101

int main(){
	int inputNum = 5, *givenNum;
	//printf("How many numbers would you like to sort: ");
	//scanf("%d",&inputNum);
	givenNum = (int *)malloc(sizeof(int)*inputNum);
	srand(time(NULL)); // Seeds of Rand function.

	if((inputNum)<1 || (inputNum)>MAX_NUM) {
		printf("Invalid input");
		exit(EXIT_FAILURE);
	}else{
		for(int i = 0; i<inputNum;i++)
			*(givenNum+i) = rand() % 1000;
	}

	printf("Input numbers are: ");
	for(int i= 0; i<inputNum;i++){
		if(i==inputNum-1) printf("%d in a row. \n",*(givenNum+i));
		else printf("%d,",*(givenNum+i));
	} // Showing given input array first.

	selection_Sort(givenNum, inputNum);

	printf("Arranged numbers are: ");
	for(int i= 0; i<inputNum;i++){
		if(i==inputNum-1) printf("%d in a row. \n",*(givenNum+i));
		else printf("%d,",*(givenNum+i));
	} // Showing arranged array by Selection sort 	
}

void selection_Sort(int *inputNum, int size){
	for(int i =0;i<size;i++){
		for(int j = i+1; j<size;j++){
			if(*(inputNum+i)>*(inputNum+j)) swap(inputNum+i,inputNum+j); 
		}
	}
}

void swap(int *inputA, int *inputB){
	int temp = *inputA;
	*inputA = *inputB;
	*inputB = temp;
} // Directly change the 'real stored values'.