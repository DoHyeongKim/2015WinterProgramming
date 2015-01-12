#include <stdio.h>
#include <math.h>

size_t binary_search( int* data, size_t N, int value){
	size_t lo = 0, hi = N-1;
	while (lo <hi){
		size_t mid = lo + (hi - lo) / 2;

		if( data[mid] < value){
			lo = mid +1;
		}else {
			hi = mid;
		}
	}

	return (hi == lo && data[lo] == value) ? lo : N;
}

int main(){
	int numList[7]= {1,2,3,4,5,6,7};

	printf("%d\n", numList[binary_search(numList,7,3)]);
}