#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 500

int fn()
{
	printf("function!\n");
	return 17;
}

void print_byte(char *addr)
{
	int i;

	for (i = 0; i < SIZE; ++i){
		printf("%d ", *(addr + i));	
	}

	printf("\n\n");
}

int main()
{
	printf("function address %d\n", &fn);

	int *new_addr = malloc(SIZE);

	memcpy(new_addr, &fn, SIZE);

	print_byte((char *)&fn);
	print_byte((char *)new_addr);

	new_addr();

	return 0;
}
