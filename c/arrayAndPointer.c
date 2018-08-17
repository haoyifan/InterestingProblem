#include <stdio.h>

// which function is correct and why

void foo(){
	char a[] = "Hello";
	char *b;
	b = a;
}

void bar() {
	char a[6];
	char *b = "Hello";
	a = b;
}

int main(){
	// foo();
	// bar();
	return 0;
}

// foo is ok but bar will not pass compiler
// it is because you cannot reassign array of a type
// to another address: it cannot be lvalue
