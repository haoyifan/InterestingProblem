#include <cstdint>
#include "trivial.hpp"
#include "reverse.hpp"
#include "search.hpp"
#include "benchmark.hpp"

void test() {
	uint64_t vut = 1;
	char buf[1000];
	for(unsigned i = 0; i < 10; ++i) {
		benchmark(rookiebench::TrivialConvert<decltype(vut), char*>(), vut, buf);
		benchmark(rookiebench::ReverseConvert<decltype(vut), char*>(), vut, buf); 
		benchmark(rookiebench::SearchConvert<decltype(vut), char*>(), vut, buf); 
		vut *= 10;

		std::cout << std::endl;
	}
}

int main(int argc, char* argv[]) {
	test();
}
