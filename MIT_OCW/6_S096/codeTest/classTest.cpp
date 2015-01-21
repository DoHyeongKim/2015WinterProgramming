#include <iostream>

class Test{
    int size;
    int num;

public:
    int getSize();
    void setSize(int _size);
    int getClassNum();
    void setClassNum(int _num);
    void print();
};

int Test::getSize(){
    return size;
}

void Test::setSize(int _size){
    size = _size;
}

int Test::getClassNum(){
    return num;
}

void Test::setClassNum(int _num){
    num = _num;
}

int main(){
    Test tc;

    tc.setClassNum(007);
    tc.setSize(4);

    std::cout << tc.getClassNum() << std::endl;
    std::cout << tc.getSize() << std::endl;

    return 0;
}