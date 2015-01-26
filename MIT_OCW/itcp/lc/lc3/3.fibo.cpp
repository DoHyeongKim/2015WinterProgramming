#include <iostream>
using namespace std;

int fibo(int n){
    cout << n << endl;
    if(n==0 || n==1){
        return 1;
    }else{
        return fibo(n-2) + fibo(n-1);
    }
}

int main(){
    cout << fibo(4) << endl;
    return 0;
}