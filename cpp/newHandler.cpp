#include <iostream>
#include <limits>
using namespace std;

void rookieHandler() {
	cout << "rookie handler called!" << endl;
	set_new_handler(nullptr);
}

int main() {
	set_new_handler(rookieHandler);
	::new int[std::numeric_limits<int>::max() * sizeof(int)];
}
