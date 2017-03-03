#include <stdio.h>

void foo(){
	int i;
	printf("%d\n", i++);
}

void bar(){
	int i = 5;
	printf("%d\n", i++);
}

int main() {
	foo();
	bar();
	foo();

	return 0;
}


// predict what would be printed in the screen
