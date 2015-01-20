#include <iostream>
using namespace std;

int main(){

    cout << "int " << sizeof(int) << endl;
    cout << "Char " << sizeof(char) << endl;
    cout << "double " << sizeof(double) << endl;

    cout << endl;

    int x; char y; float z;

    x = 'a';
    y = 'a';
    z = 'a';

    cout << "x " << x << endl;
    cout << "y " << y << endl;
    cout << "z " << z << endl;

    return 0;
}