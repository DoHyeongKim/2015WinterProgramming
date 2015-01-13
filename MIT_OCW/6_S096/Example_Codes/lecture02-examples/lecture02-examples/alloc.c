#include <stdio.h>
#include <stdlib.h>

void static_alloc(void) {
  int array[10];
  int array2[] = { 1, 2, 3, 4, 5 };
  char str[] = "blah";

  printf( "Statically allocated:\n" );
  printf( "\tarray  = %p\n", (void*) array );
  printf( "\tarray2 = %p\n", (void*) array2 );
  printf( "\tstr    = %p\n", (void*) str );
}

void dynamic_alloc(void) {
  // malloc accepts a size_t number of bytes
  int *array = malloc( 10 * sizeof( int ) );

  int *array2 = malloc(10 * sizeof(int ));

  int *array3 = malloc(10 * sizeof(int ));

  printf( "Dynamically allocated:\n" );
  printf( "\tarray = %p\n", (void*) array );
  printf( "\tarray2 = %p\n", (void*) array2 );
  printf( "\tarray3 = %p\n", (void*) array3 );
  free( array );
  free( array2 );
  free( array3 );
}

int main(void) {
  printf("Size of char type variables : %zubytes\n",sizeof(char));
  printf("Size of int type variables : %zubytes\n",sizeof(int));

  puts("");

  static_alloc();
  dynamic_alloc();
  return 0;
}
