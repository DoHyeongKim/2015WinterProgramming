#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int main(){
	char *s_str,*d_str;
	s_str = new char [20];
	d_str = new char [20];
	int i = 0;

	cout << "Enter people registration number: ";
	cin >> s_str;

	char *ptr;

	strcpy(d_str,s_str);

	cout << s_str << endl;
	cout << d_str << endl;

	return 0;
}