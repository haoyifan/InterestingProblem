#include <stdio.h>

int main() {
	char *ptr = "Hello";
	*ptr = 'B';
	return 0;
}

















// this function would generate exception because
// "Hello" is put in code segment and hence it is read only
// programmer cannot modify that portion of memory
