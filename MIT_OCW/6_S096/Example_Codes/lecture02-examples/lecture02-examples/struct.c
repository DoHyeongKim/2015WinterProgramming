#include <stdio.h>
#include <stdlib.h>

typedef struct IntPair_s {
    char c;
    char c2;
    int c3;
    int c4;
    double c5;
} IntPair;

int main(void) {
  size_t IntPairSize = sizeof( IntPair );
  printf( "Size of IntPair = %zu\n", IntPairSize);

  return 0;
}
