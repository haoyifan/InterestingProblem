#pragma once

#include <string>
#include "base.hpp"

namespace rookiebench {
	template<class T>
	class TrivialCalc : public AlgoBase<T> {
		public:
			virtual int operator()(T val) override {
				auto result = 0;
				while(val) {
					val /= 10;
					result++;
				}
				return result;
			}

			virtual std::string tag() override {
				return std::string("Trivial Implementation");	
			}
	};
}
