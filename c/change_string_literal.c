#include <stdio.h>

#define str "I am yifan"

int main() {
	char a[] = "I am yifan";
	a[0] = 'U';
	printf("%c\n", a[0]);
	char * b = str;
	*b = 'U';
	printf("%c\n", b[0]);
	b[0] = 'B';
	printf("%c\n", b[0]);
	return 0;
}
