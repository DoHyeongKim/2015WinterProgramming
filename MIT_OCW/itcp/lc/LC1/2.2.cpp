#include <iostream>
using namespace std;

int main(){

    const char * str = "Hello, World!";
    int inputNum;
    cin >> inputNum;

// (1) By using for loop

    for(int i = 0; i<inputNum ; i++){
        cout << str << endl;
    }


// (2) By using while loop
/*
    while(inputNum >0){
        cout << str << endl;
        inputNum--;
    }
*/

// (3) By using do-while loop
/*
    do{
        cout << str << endl;
        inputNum--;
    }while(inputNum>0);
*/
    return 0;
}