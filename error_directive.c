// try to compile with "gcc error_directive.c" and "gcc -DDEBUG error_directive.c"


#include <stdio.h>

#ifdef DEBUG
	#error "you defined debug jajaja!"
#endif

int main() {
	printf("success!\n");
	return 0;
}
