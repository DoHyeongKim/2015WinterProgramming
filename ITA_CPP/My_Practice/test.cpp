#include <iostream>
using namespace std;

int main(){
    int * arr = new int [4];

    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;

    for(int i = 0; i<2; i++){
        for(int j = 0; j<2; j++){
            cout << arr[i*2+j];
        }
        cout << endl;
    }
    return 0;
}