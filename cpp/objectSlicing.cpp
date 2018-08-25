#include <iostream>
using namespace std;
class A {
	public:
		int a;
};

class B : public A {
	public:
		int b;
};

int main() {
	B b1; 
	b1.a = 2;
	b1.b = 2;
	B b2; 
	b2.a = 3;
	b2.b = 3;

	A& a = b1;
	// this assignment slices off b in b2.
	// Therefore b1 is left in an inconsistent state.
	a = b2;

	cout << b1.a << endl;
	cout << b1.b << endl;

	return 0;
}

