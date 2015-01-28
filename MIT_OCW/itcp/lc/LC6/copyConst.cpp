#include <iostream>
using namespace std;

class Point{
public:
    double x,y;
    Point(double _x, double _y) {   x = _x; y = _y; };
};

int main(){

    Point p(2.0, 3.0);

    return 0;
}