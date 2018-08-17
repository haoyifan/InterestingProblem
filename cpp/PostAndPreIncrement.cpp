#include <vector>

int main() {
	vector<int> my_vec;
	
	// do stuff
	// question: which interation is more efficient

	for(auto it = my_vec.begin(); it != my_vec.end(); it++) {
		it->print();
	}

	for(auto it = my_vec.begin(); it != my_vec.end(); ++it) {
		it->print();
	}

	return 0;
}


// answer: second is better because post incrementation first copy an instance of the element before incrementing it and then returns the copy
