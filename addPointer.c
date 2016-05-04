#include <stdio.h>

// what would happen when compiling?

int main(){
	int x = 0;
	int y = 0;
	printf("%p\r\n", &x + &y);
	return 0;
}














// it would generate an error because it is invalid to add
// two pointers. This is not valid because adding two address
// has the risk of overflow.

// Subtraction of address is valid and it returns integers
