#include <iostream>
using namespace std;

int main(){
	char *text1; char *text2;

	text1 = new char [14];
	text1 = "what is this";
	string text3;

	strcpy(text2,text1);
	text3 = "what is this";

	cout << text1 << endl;
	cout << text2 << endl;
	cout << text3 << endl;
}