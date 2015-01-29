#include <iostream>

class Integer{
public:
    int val;
    Integer(int _val = 0) : val(_val) {};
};

int main(){
    Integer i(3);
    Integer j;
    Integer k[2];

    for(size_t itr = 0; itr<2; ++itr){
        std::cout << k[itr].val << endl;
    }
}

