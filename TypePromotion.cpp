/*
 The value cout to the stdout should be 4294967271. It is because unsigned int has higher hierarchy than int. Therefore int would be converted to unsigned int. The results should be of the type of the operands. So the result would be an unsigned int, which causes overflow.
 */

#include <iostream>

int main() {
	std::cout << 25u - 50 << std::endl;
	return 0;
}
