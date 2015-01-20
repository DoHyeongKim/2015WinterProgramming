#include <iostream>
#include <cmath>
using namespace std;

#define RIGHT 0
#define LEFT 1
#define UP 2
#define DOWN 3

int main(){
    int inputSize, maxNum,rotation;
    int * root;
    int nowRotation = 1;
    int nowDirection = RIGHT;
    int nowNum = 1;
    int x=-1,y=0;

    cout << "Input size of snail array: ";
    cin >> inputSize;
    rotation = ceil(inputSize/2);
    maxNum = inputSize*inputSize;

    root = new int [maxNum];

    while(1){
        if((x == y) && (x!=0) && (x<rotation)) {
            nowRotation++;
        }

        switch(nowDirection){
            case RIGHT:
                x++; break;
            case LEFT:
                x--; break;
            case UP:
                y--; break;
            case DOWN:
                y++; break;
        }

        root[y*inputSize+x] = nowNum;

        if(nowNum == maxNum) {
            break;
        }else{
            switch(nowDirection){
                case RIGHT:
                    if((nowRotation+x) == inputSize) nowDirection = DOWN;
                    break;
                case DOWN:
                    if((nowRotation+y) == inputSize) nowDirection = LEFT;
                    break;
                case LEFT:
                    if((x-nowRotation)<0) nowDirection = UP;
                    break;
                case UP:
                    if((y-nowRotation) == 0) nowDirection = RIGHT;
                    break;
            }
        }

        nowNum++;
    }
     for(int i = 0; i<inputSize;i++){
            for(int j = 0; j<inputSize;j++){
                cout << root[inputSize*i+j]<<"\t";
            }
            cout << endl;
        }
}