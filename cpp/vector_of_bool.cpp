#include <vector>
#include <iostream>

using namespace std;

int main() {
	vector<bool> bool_v{true, true, true, true};
	// uncomment this will generate error in g++ 5.4.0
	// because we cannot take address of bit in C++ object model
	// cout << &bool_v[0] << endl;

	// use universal reference to refer to the element
	auto&& bit = bool_v[0];
	// now change the internal element of bool_v
	bit = false;
	for(auto bit : bool_v)
		cout << bit << " ";
	cout << endl;

	// it is totally ok to take address for vector which does not
	// have bool as type.
	vector<int> int_v{1,2,3,4};
	cout << &int_v[0] << endl;
}
