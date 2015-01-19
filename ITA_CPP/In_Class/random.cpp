#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(){
    srand(time(NULL));
    for(int i = 0; i<4;i++)
        cout << rand() << endl;

    return 0;
}