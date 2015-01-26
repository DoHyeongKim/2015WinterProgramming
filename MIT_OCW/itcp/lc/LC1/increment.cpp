#include <iostream>
using namespace std;

int main(){
    for(size_t i = 0; i<10;){
        cout << ++i << " ";
    }
    cout << endl;

    for(size_t i = 0; i<10;++i){
        cout << i << " ";
    }
    cout << endl;

    for(size_t i = 0; i<10;){
        cout << i++ << " ";
    }
    cout << endl;

    for(size_t i = 0; i<10;i++){
        cout << i << " ";
    }
    cout << endl;
}