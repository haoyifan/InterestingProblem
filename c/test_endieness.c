#include <stdio.h>

int main() {
	int x = 1;
	char * t = &x;

	if(*t == 1) {
		printf("little endien\n");
	} else {
		printf("bit endien\n");
	}

	return 0;
}
