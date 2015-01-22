#include <iostream>
#include <cstring>
using namespace std;
#define N 2

typedef struct test_s{
    int C,R;
    int index[1][N];
} Test;

int main(){
    Test t1, t2;

    t1.C = 1;
    t1.R = 2;
    for(int i = 0; i<2;i++){
        t1.index[0][i] = i;
    }

    t2.C = 1;
    t2.R = 1;
    for(int i = 0; i<2;i++){
        t2.index[0][i] = i;
    }

    cout << memcmp(&t1,&t2,sizeof(Test)) << endl;
}