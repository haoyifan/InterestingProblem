#include <chrono>
#include <iostream>

#define REPEAT 1000000

template<class F, class... T>
void benchmark(F f, T... t) {
	auto start = std::chrono::system_clock::now();
	auto repeat = 0;
	int res;

	while(repeat++ < REPEAT) {
		res = f(t...);		
	}

	auto end = std::chrono::system_clock::now();
	auto elapsed =
	    std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	
	std::cout << "=====" << std::endl;
	std::cout << "Total time took: " << elapsed << " milliseconds" << std::endl;
	std::cout << "Result: " << res << std::endl;
	std::cout << "Implementation: " << f.tag() << std::endl;
	return;
}

