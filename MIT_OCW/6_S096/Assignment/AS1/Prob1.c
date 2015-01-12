#include <stdio.h>

union float_bits{
	float f;
	size_t bits;
};

void print_hex( float f ){
	union float_bits t;
	t.f = f;

	printf("input Number is %f\n",f);
	printf("The float looks like 0x%x in hex.\n",t.bits);
}

void print_dec( float f ){
	union float_bits t;
	t.f = f;

	printf("In integer form like %d in dec", t.bits);
}

int main(void){
	float input;
	scanf("%f",&input);

	print_hex(input);
	print_dec(input);
	puts("");

	int a = 0x3fc00000;
	printf("%x\n",a);
}