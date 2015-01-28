#include <iostream>
using namespace std;

class Point{
    double x,y;
    Point(double _x, double _y) : x(_x), y(_y) {};
    void print() const {    cout << "(" << x << "," << y << ")";    };
};

class Vector{
    Point start, end;
    Vector(double _xStart = 0, double _yStart = 0,double _xEnd = 0, double _yEnd = 0) {    start = Point(_xStart, _xEnd); end = Point(_xEnd,_yEnd);    };

};

int main(){

    return 0;
}