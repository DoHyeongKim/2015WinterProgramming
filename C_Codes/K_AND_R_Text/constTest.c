#include <stdio.h>
#include <string.h>

/*
void commonFuncPtr(char ** inputStr){
    *(inputStr) = (char *) &("Hello, Func");
}

void commonFuncPtr(char * inputStr){
    printf("%d\n",inputStr);
}
*/
void commonFuncArr(char inputStr[]){
    inputStr[7] = 'F';
    inputStr[8] = 'u';
    *(inputStr+9) = 'n';
    *(inputStr+10) = 'c';
    inputStr[11] = '\0';
    printf("In funcArr : %s\n",inputStr);
}
/*
void constFuncArr(const char inputStr[]){
    inputStr[7] = 'F';
    inputStr[8] = 'u';
    inputStr[9] = 'n';
    inputStr[10] = 'c';
    inputStr[11] = '\0';
    printf("In constFuncArr : %s\n",inputStr);
} WE CANNOT CHANGE THE VALUE OF VARIABLE WITH 'CONST' SYMBOL
*/
/*
void constFunc(const char *inputStr){
    inputStr = "Hello, const";
}
*/

int main(void){
    char *testPtr = "Hello, World";
    char testArr[] = "Hello, World";
    char testArr2[] = "Hello, World";

    printf("Address of given text with Pointer : %p\n", (void *)testPtr);
    printf("Address of the pointer indicating the sentence: %p\n", (void *)&testPtr);
    puts("");
    printf("Address of given text with Array : %p\n", testArr);
    printf("Address of the pointer indicating the sentence: There is no ptr with arr");
    puts("");
    printf("With nothing (ptr): %s\n", testPtr); /* Print initial sentence"  */
    printf("With nothing (arr): %s\n", testArr); /* Print initial sentence"  */
    printf("With nothing (constArr): %s\n", testArr2); /* Print initial sentence"  */
    puts("");

    //commonFuncPtr(&testPtr);
    //commonFuncPtr(testPtr);
    commonFuncArr(testArr);
    //constFuncArr(testArr2);

    printf("After commonFunc with Pointer : %s\n", testPtr); /* Print return value of the function without CONST Declaration */
    printf("After commonFunc with Array : %s\n", testArr); /* Print return value of the function without CONST Declaration */
    //printf("After commonFunc with Array : %s\n", testArr2); /* Print return value of the function without CONST Declaration */

//    constFunc(testStr);

  //  printf("%s\n", testStr); /* Print return value of the function with CONST Declaration */
    return 0;
}