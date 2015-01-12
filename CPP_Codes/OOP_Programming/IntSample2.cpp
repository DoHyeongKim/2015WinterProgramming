#include <iostream>
using namespace std;

class IntSample2{
public:
	void showScore();
	int score;
};

void IntSample2::showScore(){
	cout << "Score: " << score << endl;
}

int main(){
	IntSample2 Obj;

	Obj.score = 100;
	Obj.showScore();

	return 0;
}