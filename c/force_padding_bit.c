#include <stdio.h>

typedef struct test_a {
	unsigned int x : 1;
	unsigned int : 0;
	unsigned int y : 1;
} my_struct_A;

typedef struct test_b {
	unsigned int x : 1;
	unsigned int : 1;
	unsigned int y : 1;
} my_struct_B;

typedef struct test_c {
	unsigned int x : 1;
	unsigned int y : 1;
} my_struct_C;

int main() {
	// custom type sizeof needs to have parenthesis
	printf("struct A size: %lu\nstruct B size: %lu\nstruct C size: %lu\n", sizeof(my_struct_A), sizeof(my_struct_B), sizeof(my_struct_C));
	return 0;
}
