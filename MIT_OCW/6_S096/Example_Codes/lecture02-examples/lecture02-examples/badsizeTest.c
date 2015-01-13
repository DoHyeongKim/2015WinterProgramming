#include <stdio.h>
#include <stdlib.h>

int main(){
    int *array = malloc(sizeof(int)*10);

    array[13] = 24;

    for(size_t i = 0; i<15; i++)
        printf("Array [%zu] : %d\n", i,array[i]);

    return 0;
}