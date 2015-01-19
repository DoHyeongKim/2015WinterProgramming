#include <iostream>
using namespace std;

int main(){

    int x = 0;
/*
    while(x<=100){
        cout << x << endl;
        x=x+2;
    }
*/
    while(x<=100){
        x++;
        if(x%2) cout << x;
        else continue;
    }
}