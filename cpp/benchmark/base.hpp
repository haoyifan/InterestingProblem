#pragma once

#include <string>

namespace rookiebench {
	template<class... Ts>
	class AlgoBase {
		public:
			virtual int operator()(Ts... t) = 0;
			virtual std::string tag() = 0;
	};
}
