#include <cstdio>

using namespace std;

class A {};

int main() {
	// printf is not type safe
	printf("%d %d\n", A(), A());
	return 0;
}
