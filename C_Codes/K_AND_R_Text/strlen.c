#include <stdio.h>

int strlenMade(char * inputStr){
    int i;

    for(i = 0; *inputStr != '\0';inputStr++){
        i++;
    }

    return i;
}

int main(int argc, char **argv){
    if(argc !=2){
        printf("How to use: %s [word would like to get length of the word] \n", argv[0]);
        return 0;
    }

    printf("The length of the input word [%s] is : %d \n", argv[1], strlenMade(argv[1]));
}