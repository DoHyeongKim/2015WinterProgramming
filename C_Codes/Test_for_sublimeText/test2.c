#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	/* Whenever allocating storage a runtime
	we use mechanisms of 'heap'. as using 'malloc'
	function, we can request the amount of memory
	spaces that I wanted*/

	/* CALL to malloc includes a parameter that deter
	mines the size of storage required to hold the 
	int and float */

	int i, *pi;
	float f, *pf;

	/*
	pi = (int *) malloc (sizeof(int));
	pf = (float *) malloc (sizeof(float));
	*/
	i = 1024; f = 3.14;
	pi = &i; pf = &f;
	
	/*
	*pi = 1024;
	*pf = 3.14;
	*/
	
	printf("an integer = %d, a float = %.2f \n", *pi, *pf);

	free(pi); free(pf);

	return 0;
}