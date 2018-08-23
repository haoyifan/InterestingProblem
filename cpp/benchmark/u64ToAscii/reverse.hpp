#pragma once

#include <string>
#include <algorithm>
#include "base.hpp"
#include "digitsCntBenchmark/strengthreduction.hpp"

namespace rookiebench {
	template<class T, class BT>
	class ReverseConvert: public AlgoBase<T, BT> {
		public:
			virtual int operator()(T val, BT buf) override {
				auto len = StrengthReductionCalc<T>()(val);
				auto end = buf + len;
				*end = '\0';
				while(val) {
					*end-- = '0' + val % 10;
					val /= 10;
				}
				return len;
			}

			virtual std::string tag() override {
				return std::string("Reverse Implementation");	
			}
	};
}
