#include <stdio.h>

typedef struct IntPair_s {
  int first;
  int second;
} IntPair;

int main(void) {
    IntPair pair1, pair2;

    pair1.first = 1;
    pair1.second = 2;

    pair2.first = 3;
    pair2.second = 4;

    printf("%d,%d\n", pair1.first, pair1.second);
    printf("%d,%d\n", pair2.first, pair2.second);

    IntPair* pairPtr1 = &pair1;
    IntPair* pairPtr2 = &pair2;

    printf("%d,%d\n", pairPtr1->first, pairPtr1->second);
    printf("%d,%d\n", pairPtr2->first, pairPtr2->second);
}
