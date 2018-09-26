#include <iostream>

using namespace std;

// put lambda into heap
int main() {
	auto lambda = [](int a){std::cout << a << std::endl;};

	auto newLambda = new decltype(lambda)(lambda);

	(*newLambda)(2);

    std::cout << "lambda (without capture) size is " << sizeof(decltype(lambda)(lambda)) << std::endl;

    int i;

	auto lambda1 = [i](int a){std::cout << a << std::endl;};

    std::cout << "lambda (with capture of an int) size is " << sizeof(decltype(lambda1)(lambda1)) << std::endl;
}
