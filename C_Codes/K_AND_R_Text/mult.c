#include <stdio.h>

int main(){
    int a = 8;
    int b = (int)(sizeof(int));
    printf("%d\n", a*b);
    return 0;
}