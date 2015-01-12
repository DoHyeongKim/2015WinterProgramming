#include <iostream>
using namespace std;

int main(){
	int r;
	float CArea, Cference;

	cout << "input radius : ";
	cin >> r;
	CArea = 2*(float)3.14*r;
	Cference = r*r*(float)3.14;

	cout << "Length of the circle" << CArea << endl;
	cout << "Area of the circle" << Cference << endl;
}