#include <iostream>

using namespace std;

// put lambda into heap
int main() {
	auto lambda = [](int a){std::cout << a << std::endl;};

	auto newLambda = new decltype(lambda)(lambda);

	(*newLambda)(2);
}
