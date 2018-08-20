#include <string>
#include <queue>
#include <iostream>
#include <unordered_set>
#include <vector>
#include <limits>
using namespace std;

class Solution {
	public:
		bool diffByOne(const string& a, const string& b) {
			auto diff = 0;
			for(int i = 0; i < a.size(); ++i) {
				if(a[i] != b[i]) diff++;
			}
			return diff == 1;
		}

		// int impl(string start, string end, unordered_set<string>& dict, int curr) {
		// 	if(diffByOne(start, end))
		// 		return curr + 1;

		// 	if(dict.empty()) {
		// 			return 0;
		// 	}
		// 	int minval = std::numeric_limits<int>::max();

		// 	vector<string> v(dict.begin(), dict.end());

		// 	for(auto& s : v) {
		// 		if(diffByOne(start, s)) {
		// 			dict.erase(s);
		// 			auto val = impl(s, end, dict, curr + 1);
		// 			if(val != 0) minval = min(val, minval);
		// 			dict.insert(s);
		// 		}
		// 	}
		// 	if(minval == std::numeric_limits<int>::max()) return 0;
		// 	return minval;
		// }

		// int ladderLength(string start, string end, unordered_set<string> &dict) {
		// 	return impl(start, end, dict, 0);
		// }

		int ladderLength(string start, string end, unordered_set<string> &dict) {
			int res = 1;
			queue<string> q;
			q.push(start);

			while(!q.empty()) {
				auto size = q.size();
				while(size-- > 0) {
					auto curr = q.front(); q.pop();
					if(diffByOne(curr, end))
						return res + 1;

					unordered_set<string> toDelete;
					for(auto& s : dict) {
						if(diffByOne(curr, s)) {
							toDelete.insert(s);
							q.push(s);
						}
					}
					for(auto& s:toDelete)
						dict.erase(s);
				}
				res++;
			}
			return 0;
		}

};

int main() {
	unordered_set<string> s{"hot","dot","dog","lot","log"};
	cout << Solution().ladderLength("hit", "cot", s);
}
