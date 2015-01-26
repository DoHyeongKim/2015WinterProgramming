#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char frag1[] = "I'm a s";
    char frag2[] = "tring";
    char frag3[20];
    char finalString[] = "";

    cout << frag1 <<endl;
    cout << frag2 <<endl;
    cout << frag3 <<endl;
    cout << finalString <<endl;

    strcpy(frag3, frag1);
    cout << frag1 <<endl;
    cout << frag2 <<endl;
    cout << frag3 <<endl;
    cout << finalString <<endl;
    strcat(finalString, frag3);
    cout << frag1 <<endl;
    cout << frag2 <<endl;
    cout << frag3 <<endl;
    cout << finalString <<endl;
    strcat(finalString, frag2);
    cout << frag1 <<endl;
    cout << frag2 <<endl;
    cout << frag3 <<endl;
    cout << finalString <<endl;

    return 0;
}