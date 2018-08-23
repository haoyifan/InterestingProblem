#include "trivial.hpp"
#include "strengthreduction.hpp"
#include "search.hpp"
#include "benchmark.hpp"

void test() {
	unsigned long vut = 1;
	for(unsigned i = 0; i < 10; ++i) {
		benchmark(rookiebench::TrivialCalc<decltype(vut)>(), vut);
		benchmark(rookiebench::StrengthReductionCalc<decltype(vut)>(), vut); 
		benchmark(rookiebench::SearchCalc<decltype(vut)>(), vut); 
		vut *= 10;

		std::cout << std::endl;
	}
}

int main(int argc, char* argv[]) {
	test();
}
