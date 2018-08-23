#pragma once

#include <string>
#include "base.hpp"

namespace rookiebench {
	template<class T>
	class SearchCalc : public AlgoBase<T> {
		public:
			virtual int operator()(T val) override {
				if(val < 10) return 1;
				if(val < 100) return 2;
				if(val < 1000) return 3;
				if(val < 1000000000000) {
					if(val < 100000000) {
						if(val < 1000000) {
							if(val < 10000) return 4;
							return 5 + (val >= 100000);
						}
						return 7 + (val >= 10000000);
					}
					if(val < 10000000000)
						return 9 + (val >= 1000000000);
					return 11 + (val >= 100000000000);
				}
				return 12 + operator()(val / 1000000000000);
			}

			virtual std::string tag() override {
				return std::string("Search Implementation");	
			}
	};
}
