#include <stdio.h>

int main(){
	typedef struct IntPair_s{
		int first;
		int second;
	}IntPair;

	IntPair pair;
	pair.first = 3;
	pair.second = 1;
	IntPair *pairPtr = &pair;

	printf("%d\n",pairPtr->first);
	printf("%d\n",pairPtr->second);

	printf("%d\n",pair.first);
	printf("%d\n",pair.second);

	return 0;
}