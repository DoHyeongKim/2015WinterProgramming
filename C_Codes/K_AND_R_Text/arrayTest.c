#include <stdio.h>

int main(){
    int a[5];

    for(int i = 0; i<6;i++){
        a[i] = (i+1);
    }

    for(size_t i = 0; i<6;i++){
        printf("%d, ", a[i]);
        printf("%p, ", (void *)&(a[i]));
    }

    return 0;
}