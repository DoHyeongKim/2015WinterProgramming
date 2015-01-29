#include <iostream>
using namespace std;

class IntegerArray{
public:
    int *data; // Pointer to the first element
    size_t size; // Number of elements in the array
    IntegerArray(size_t _size) :size(_size) , data((new int [_size])){}
    IntegerArray(IntegerArray &o) : size(o.size), data((new int [o.size])){
        for(size_t i = 0; i<size; ++i){
            data[i] = o.data[i];
        }
    }
    ~IntegerArray() {
        delete [] data;
    }
};

int main(){
    IntegerArray a(2);
    a.data[0] = 4; a.data[1] = 5;

    if(true){
        IntegerArray b(a);
    }
    cout << a.data[0] << endl;
}