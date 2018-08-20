#include <vector>
#include <iostream>
#include <utility>
#include <unordered_map>
using namespace std;

class Solution {
	public:
		int longestConsecutive(vector<int> &num) {
			unordered_map<int, int> m;
			int res = 0;

			for(auto val : num) {
				if(m.find(val) == m.end()) {
					int left = 0, right = 0;
					if(m.find(val - 1) != m.end())  left = m[val - 1];
					if(m.find(val + 1) != m.end())  right = m[val + 1];
					int length = left + right + 1;
					res = max(length, res);
					m[val] = length;
					m[val - left] = length;
					m[val + right] = length;
				}
			}

			return res;
		}
}; 

int main() {
	vector<int> v{1,2,0,1};
	cout << Solution().longestConsecutive(v);
}
