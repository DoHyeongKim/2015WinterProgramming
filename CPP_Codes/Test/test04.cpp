#include <iostream>
using namespace std;

// Namespace Concept

int main(){
	char ch = 'y', name[30] = "Kabdol", name2[] = "Kabdol";

	cout << hex << (int)&ch << endl;
	cout << hex << name << endl;
	cout << hex << &name[0] << endl; // 16-digit format console output

	return 0;
}
