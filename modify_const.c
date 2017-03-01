#include <stdio.h>

int main() {
	const int a = 1;
	int * b = &a;

	*b = 2;
	printf("value of a is: %d\n", a);
	
	int c = 1;
	const int * d = &c;
	c = 2;
	printf("value of d desinate: %d\n", *d);
	
	return 0;
}
