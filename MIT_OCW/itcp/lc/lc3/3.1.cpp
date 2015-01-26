#include <iostream>
using namespace std;

int raiseToPower(const int a, const size_t b){
    int x = 1;
    for(size_t i = 0; i<b ; i++){
        x *= a;
    }
    return x;
}

int main(){
    int threeExpFour = raiseToPower(3,4);
    cout << "3^4 is " << threeExpFour << endl;

    int sixExpFive = raiseToPower(6,5);
    cout << "6^5 is " << sixExpFive << endl;

    int twelveExpTen = raiseToPower(12,10);
    cout << "12^10 is " << twelveExpTen << endl;

    return 0;
}