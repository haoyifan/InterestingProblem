#include <iostream>
#include <cstring>
using namespace std;
struct Base{
	char *name;
	Base(char *n) : name(strdup(n)){}
	Base& operator= (const Base& other){
		free (name);
		name = strdup (other.name);
		cout << "Base assignment called: " << name << endl;
	}
};

struct A:virtual Base{
	int val;
	A():Base("A"){}
};

struct B:virtual Base{
	int bval;
	B():Base("B"){}
};

struct Derived:public A, public B{
	Derived():Base("Derived"){}
};

void func(Derived &d1, Derived &d2)
{
	d1 = d2;
}

int main() {
	Derived d1, d2;
	func(d1, d2);
}
