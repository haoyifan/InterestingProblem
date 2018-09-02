#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
	public:
		bool isValidSegment(const string& s) {
			int val = 0;
			for(int i = 0; i < s.size(); ++i) {
				val = val * 10 + s[i] - '0';
				if(val < 0 || val > 255) return false;
			}
			return true;
		}

		void impl(int low, vector<string>& result, const string& s, string curr, int level) {
			if(low >= s.size()) return;
			if(level == 3) {
				if(s[low] == '0' && low < s.size() - 1) return;
				if(isValidSegment(s.substr(low))) {
					curr += s.substr(low);
					result.push_back(curr);
				}
				return;
			}

			int len = 1;
			while(low + len <= s.size() && isValidSegment(s.substr(low, len))) {
				auto tmp = curr;
				curr += s.substr(low, len) + ".";
				impl(low + len, result, s, curr, level + 1);
				curr = tmp;
				len++;
				if(s[low] == '0') return;
			}
			return;
		}

		vector<string> restoreIpAddresses(string s) {
			vector<string> result;
			string curr;
			impl(0, result, s, curr, 0);
			return result;
		}
};

int main () {
	auto v = Solution().restoreIpAddresses("0279245587303");
	for(auto i : v)
		cout << i << endl;
}
