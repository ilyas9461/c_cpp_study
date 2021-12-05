
#include <stdio.h>

typedef struct {
	int real;
	int im;
} complex;


complex a, b;
complex obj;

complex complex_add(complex a, complex b);

int main(void)
{
	a.real = 4; 
	a.im = 7; 

	b.real = 6;
	b.im = 9;

	obj = complex_add(a, b);
	printf("real: %d imaginal:%d \n", obj.real, obj.im);

	return 0;
}

complex complex_add(complex a, complex b) {

	complex result;

	result.real = a.real + b.real;
	result.im = a.im + b.im;

	return result;
}


