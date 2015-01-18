#include <iostream>
using namespace std;

int main(){
    int a[5];

    for(int i = 0; i<6;i++){
        a[i] = (i+1);
    }

    for(size_t i = 0; i<6;i++){
        cout << a[i] << ", ";
    }

    return 0;
}