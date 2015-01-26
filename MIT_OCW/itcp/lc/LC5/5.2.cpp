#include <iostream>
using namespace std;

int main(){
    const int conInt = 5;
    int Int = 10;
    const int conInt2 = 12;

    const int* conPtr;
    int * const ptr = &Int;
    const int* const ptr2 = &conInt2;


    conPtr = &conInt;
    //ptr = &Int;
    *conPtr = (const) 10;

    cout << *conPtr << endl;
    cout << *ptr << endl;
    cout << *ptr2 << endl;

    //*conPtr = 10;
    *ptr = 20;

    cout << *conPtr << endl;
    cout << *ptr << endl;

    return 0;
}