#include <iostream>
using namespace std;
/*  In CPP Way
void increment(int &a){
    a++;
}
*/

void increment (int *a){
    ++*a;
}

int main(){

    int a = 0;
    cout << "a = " << a << endl;

    increment(&a);

    cout << "(In main()) a = " << a << endl;

    return 0;
}