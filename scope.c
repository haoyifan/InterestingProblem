#include <stdio.h>

// what could be the problem

int *foo() {
	int x = 0;
	return &x;
}

int main() {
	int *t = foo();
	return 0;
}





















// out of scope
