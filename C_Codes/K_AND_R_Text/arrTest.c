#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void changeVal(char inputArr[]){
    inputArr [7] = 'F';
    inputArr [8] = 'u';
    inputArr [9] = 'n';
    inputArr [10] = 'c';
    inputArr[11] = '\0';
}

void changeValPtr(char *inputArr){
    for(size_t i = 0; i<strlen(inputArr);++i){
        printf("%c",*(inputArr+i));
    }
    puts("");

    *(inputArr+7) = (char)malloc(sizeof(char)*1);
    *(inputArr+7) = 'F';
}

int main(){
    //int arrTest[] = {111,222,333};
    char arrTest[] = "Hello, World";
    char *ptrTest = "Hello, World";

    //for(size_t i = 0; i<3;i++)
        //printf("%d\t",arrTest[i]);

    printf("%s\n",arrTest);

    puts("");

    changeVal(arrTest);
    changeValPtr(ptrTest);

    //for(size_t i = 0; i<3;i++)
      //  printf("%d\t",arrTest[i]);

    printf("%s\n", arrTest);

    return 0;
}