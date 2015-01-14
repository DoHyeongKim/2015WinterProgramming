#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    char **stringPtr;

    stringPtr = (char **) malloc(sizeof(char *) * 5) ;
    /*
    for(size_t i = 0; i < 5; ++i){
        stringPtr[i] = (char *) malloc (sizeof(char) * 10);
    }
    */

    stringPtr[0] = "Hello";
    stringPtr[1] = ",";
    stringPtr[2] = "World!";
    stringPtr[3] = "C";
    stringPtr[4] = "Language";

    for(size_t i = 0; i<5;++i){
        printf("%s\t", stringPtr[i]);
        printf("%4zu\n",strlen(stringPtr[i]));
    }

    free(stringPtr);

    return 0;
}