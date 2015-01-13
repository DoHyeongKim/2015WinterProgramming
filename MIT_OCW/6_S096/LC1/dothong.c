#include <stdio.h>

int do_thing(float a, float b){
    printf("Do_thing starts\n");
    printf("%f,%f\n", a,b);
    printf("Do_thing ends\n");
    return 0;
}

void call(void){
    printf("call starts\n");
    float a = 0.1 ,b = 0.2;

    /* do stuff */
    do_thing(a,b);
    /* do more */
    printf("call ends\n");
}

int main(void){
    printf("main starts\n");
    call();
    printf("main ends\n");
    return 0;
}