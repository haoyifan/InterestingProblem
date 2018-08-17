#include <stdio.h>

typedef struct test_s {
	unsigned int a;
	unsigned int b: 4;
} my_struct;

int main() {
	my_struct tmp = {1, 2};
	printf("address of field a: %lu\naddress of field b: %lu\n", &tmp.a, &tmp.b);
	return 0;
}
