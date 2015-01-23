#include <iostream>
using namespace std;

size_t getStr(char **str, FILE *input){
    size_t chars_to_read = BLOCK_SIZE;
    size_t length = 0;

    size_t chars = 0;
    while ((chars = fread(*str + length, 1 , chars_to_read,input))){

    }
    return length;
}

void encrypt(char *string, size_t length){

}

int main(){

    return 0;
}