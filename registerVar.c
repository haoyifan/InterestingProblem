#include <stdio.h>

// what would happen when compiling?
// hint: it takes an address of a register

int main() {
	register int x;
	x = 2;
	printf("the address of x is %p \r\n", &x);
	return 0;
}















// keyword register tells the compiler that the variable should be
// stored in register to improve the program speed, but the compiler
// could igore this optimization. However, although compiler could
// ignore that, this would generate an error because register does
// not have address. Only memory has address
