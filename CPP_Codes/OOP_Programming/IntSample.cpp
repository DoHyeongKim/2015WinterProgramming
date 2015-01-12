#include <iostream>
using namespace std;

class IntSample{
public:
	void showScore();
	void setScore(int inputScore);
	int getScore();
private:
	int score;
};

void IntSample::showScore(){
	cout << "Score: " << score << endl;
}

void IntSample::setScore(int inputScore){
	score = inputScore;
}

int IntSample::getScore(){
	return score;
}

int main(){
	IntSample Obj;
	IntSample *objPrt;
	objPrt = &Obj;

	objPrt->setScore(2);
	objPrt->showScore();
	Obj.setScore(3);
	Obj.showScore();

	return 0;
}