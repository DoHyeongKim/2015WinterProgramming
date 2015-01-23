#include <iostream>
using namespace std;

class AA{
    int x,y;
public:
    AA(){};
    AA(int _x, int _y) {    x = _x; y = _y;    };
    void setx(int _x) {    x = _x;   };
    void sety(int _y) {    y = _y;   };
    int getx(){    return x;   };
    int gety(){    return y;   };
};

int main(){
    AA a;
    cout << a.x;
    a.x = 10;
    a.setx(10);

    return 0;
}