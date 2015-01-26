#include <iostream>
#include <cctype>
using namespace std;

int main(){
    const char *str = "Test 1 for Ctype Header File With Its Methods";
    char current = str[0];

    for(size_t i = 0; current != '\0' ; current = str[++i]){
        if(isalpha(current))
            cout << (char)(isupper(current) ? tolower(current) : current);
        else
            cout << ' ';
    }
    cout << endl;
    return 0;
}