#include <iostream>
#include <limits>
using namespace std;

void rookieHandler() {
	cout << "rookie handler called!" << endl;
	set_new_handler(nullptr);
}

int main() {
	set_new_handler(rookieHandler);
	for(int i = 0; i < 100; ++i)
		malloc(std::numeric_limits<int>::max());
	cout << "after malloc" << endl;
	::new int[std::numeric_limits<int>::max() * sizeof(int)];
}
