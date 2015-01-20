#include <iostream>
using namespace std;

int main(){
    char arr[6] = "*****";

    for(size_t i = 0; i<5;i++){
        for(size_t j = 5-i; j<5;j++){
            cout << " ";
        }
        cout << arr+i<<endl;
    }
    return 0;
}