#pragma once

#include <string>
#include "base.hpp"

// Use more comparison operations than division. Replace expensive operations
// with cheaper ones to accelerate.
namespace rookiebench {
	template<class T>
	class StrengthReductionCalc: public AlgoBase<T> {
		public:
			virtual int operator()(T val) override {
				auto result = 0;
				while(val) {
					if(val < 10) return result + 1;
					if(val < 100) return result + 2;
					if(val < 1000) return result + 3;
					if(val < 10000) return result + 4;

					val /= 10000U;
					result += 4;
				}
				return -1;
			}

			virtual std::string tag() override {
				return std::string("Strength Reduction Implementation");	
			}
	};
}
