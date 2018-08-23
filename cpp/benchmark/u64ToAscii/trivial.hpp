#pragma once

#include <string>
#include <algorithm>
#include "base.hpp"

namespace rookiebench {
	template<class T, class BT>
	class TrivialConvert: public AlgoBase<T, BT> {
		public:
			virtual int operator()(T val, BT buf) override {
				auto start = buf;
				while(val) {
					*buf++ = '0' + val % 10;
					val /= 10;
				}
				*buf = '\0';
				std::reverse(start, buf);
				return buf - start;
			}

			virtual std::string tag() override {
				return std::string("Trivial Implementation");	
			}
	};
}
