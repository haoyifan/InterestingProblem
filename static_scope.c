#include <stdio.h>

void a() {
	static int x;
	printf("%d\n", x++);
	return;
}

//void b() {
//	printf("%d\n", x++);
//	return;
//}

int main() {
	a();
	a();
//	b();

	return 0;
}
