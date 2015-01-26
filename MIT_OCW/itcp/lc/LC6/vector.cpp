#include <iostream>
using namespace std;

class Vector{
public:
    const double xStart;
    const double yStart;
    const double xEnd;
    const double yEnd;
    Vector(double _xStart, double _yStart, double _xEnd, double _yEnd) : xStart(_xStart), yStart(_yStart), xEnd(_xEnd), yEnd(_yEnd) {};
    void printVector() { cout << "(" << xStart << "," << xEnd << ") -> (" << xEnd << "," << yEnd << ")" << endl;};
    // We can call this area by field (=member), and this area consist of
    // field(member) variables and functions
};

int main(){
    Vector v1(0.0, 0.0, 1.5, 2.0);
    Vector v2(1.2, 1.5, 2.5, 7.0);

    v1.printVector();
    v2.printVector();

    return 0;

}

