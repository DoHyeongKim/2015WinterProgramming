#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void arrInit(int *input, size_t arrSize){
    for(size_t i = 0; i<arrSize; i++){
        scanf("%d", (input+(int)i));
    }
}

void arrRand(int *input, size_t arrSize){

    srand(time(NULL));

    do{
        for(size_t i = 0; i<arrSize; i++){
            *(input+(int)i) = rand()%10;
        }

    }while((input[0] == input[1])||(input[1]==input[2])||(input[2]==input[0]));
}

int main(){
    // 야구게임에서 기본적으로 생성할 3개의 숫자를 생성하고, 저장한다.

    int save[3]; // 3개의 숫자 생성 및 저장

    int choice;
    scanf("%d", &choice);

    switch(choice){
        case 1: arrInit(save, sizeof(save)/4); break;
        case 2: arrRand(save, sizeof(save)/4); break;
        default : printf("Invalid input Error\n");
    }

    for(size_t i = 0; i<3; i++){
        printf("%d\n", save[i]);
    }

    return 0;
}