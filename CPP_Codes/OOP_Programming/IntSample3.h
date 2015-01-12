#ifndef _INTSAMPLE_H_
#define _INTSAMPLE_H_

#include <iostream>
using namespace std;

class IntSample3{
public:
	void showScore();
	void setScore(const int s); // Prototype Initialization is "IMPORTANT!!!!"
	int getScore();
private:
	int score;
};

#else
#endif