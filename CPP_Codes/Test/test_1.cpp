#include <cstddef>
#include <iostream>

void f(int* pi){
	std::cout << pi << "Pointer to integer overload\n";
}

void f(double * pd){
	std::cout << pd << "Pointer to double overload\n"	;
}

void f(std::nullptr_t nullp){

	std::cout << "null pointer overload";
}

int main(){
	int * pi; double * pd;

	f(pi);
	f(pd);
	f(nullptr);
}