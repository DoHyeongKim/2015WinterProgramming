#include <iostream>
using namespace std;

int main(){
    int x[100] = {0};
  //  int y;

    x[0] = 1;
    x[2] = 3;
    x[99]  = 100;

    for(size_t i = 0; i < 100; i++){
        cout << x[i] << endl;
    }

//    cout << "Y = " <<  y << endl;
    return 0;
}