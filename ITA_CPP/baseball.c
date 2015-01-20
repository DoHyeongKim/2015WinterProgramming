#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void arrInit(int *input, size_t arrSize){
    printf("Input 3 numbers of soultion\n");
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

    printf("solutions were made successfully\n");
}

int main(){
    // 야구게임에서 기본적으로 생성할 3개의 숫자를 생성하고, 저장한다.
    while(1){

        int save[3]; // 3개의 숫자 생성 및 저장

        int choice;
        printf("If you want to make solution number of yourself, insert 1. If you want to make it randomly, insert 2 : ");
        scanf("%d", &choice);

        switch(choice){
            case 1: arrInit(save, sizeof(save)/4); break;
            case 2: arrRand(save, sizeof(save)/4); break;
            default : printf("Invalid input Error\n");
        }
        int input[3];
        int strike = 0;
        int ball = 0;

        printf("Your input Numbers are (ex 3 2 4) : ");

        for(int i = 0; i<3;i++){
            scanf("%d", &input[i]);
        }

        for(size_t i = 0; i<3;i++){
            if(input[i] == save[i]){
                strike++;
            }else{
                for(size_t j = 0; j<3;j++){
                    if(input[i]==save[j]){
                        ball++;
                    }
                }
            }
        }

        printf("%d Strikes, %d Balls\n", strike, ball);
        getchar();

        if(strike == 3) {
            char more;
            printf("Game was over, do you wanna play more? (y/n) : ");

            scanf("%c",&more);

            switch(more){
                case 'y' : continue;
                case 'n' : break;
                default : printf("Input was not clear, exit the program\n"); break;
            }
            break;
        }

    }

    return 0;
}