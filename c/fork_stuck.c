#include <stdio.h>
#include <stdlib.h>

int main() {
	int * m;
	m = calloc(1, sizeof(int));
	if(fork()){
		while(*m == 0);
		*m = 0;
		printf("a\n");
	} else {
		*m = 1;
		while(*m == 1);
		printf("b\n");
	}

	return 0;
}
