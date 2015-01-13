#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *array = malloc( 10 * sizeof( int ) );
  for( int i = 0; i < 10; ++i ) {
    printf("%d\n",i);
    array[i] = i;
  }

  for( size_t i = 0; i < 10; i++ ) {
    printf("%zu",i);
    printf("array[%zu] : %d\n",i,array[i]);
  }

  free( array );
  return 0;
}
