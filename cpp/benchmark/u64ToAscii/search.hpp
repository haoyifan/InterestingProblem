#pragma once

#include <string>
#include <algorithm>
#include "base.hpp"
#include "digitsCnt/search.hpp"

namespace rookiebench {
	template<class T, class BT>
	class SearchConvert: public AlgoBase<T, BT> {
		public:
			virtual int operator()(T val, BT buf) override {
				static const char digits[] =
				"0001020304050607080910111213141516171819"
				"2021222324252627282930313233343536373839"
				"4041424344454647484950515253545556575859"
				"6061626364656667686970717273747576777879"
				"8081828384858687888990919293949596979899";

				const auto len = SearchCalc<T>()(val);
				auto idx = len;
				buf[idx--] = '\0';

				while(val >= 100) {
					const auto i = (val % 100) * 2;
					val /= 100;
					buf[idx--] = digits[i + 1];
					buf[idx--] = digits[i];
				}

				if(val < 10) buf[idx] = '0' + val;
				else {
					const auto i = (val % 100) * 2;
					buf[idx--] = digits[i + 1];
					buf[idx--] = digits[i];
				}

				return len;
			}

			virtual std::string tag() override {
				return std::string("Search Implementation");	
			}
	};
}
