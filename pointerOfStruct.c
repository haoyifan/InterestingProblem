#include <stdio.h>

// what would happen when compiling?

typedef struct x{
	int data : 4;
}my_struct;

void foo() {
	my_struct is;
	printf("address of data is %p \r\n", &is.data);
}

int main() {
	foo();
	return 0;
}










// it would generate error because it is invalid to take address
// of bit-field. Pointers can only address whole byte. Even we define
// data as 8 or 16 or 32 bits field, it is still invalid.
