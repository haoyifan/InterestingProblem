#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
	public:
		bool wordBreak(string s, vector<string>& wordDict) {
			unordered_set<string> dict(wordDict.begin(), wordDict.end());

			vector<bool> dp(s.size() + 1, false);
			dp[0] = true;

			for(int i = 0; i < s.size(); ++i) {
				for(int j = i + 1; j < s.size() + 1; ++j) {
					if(dict.find(s.substr(i, j - i)) != dict.end()) {
						dp[j] = (dp[i] == true ? true : false) || dp[j] ;
					}
				}
			}
			return dp.back();
		}
};

int main() {
	vector<string> dict{string("leet"), string("code")};
	cout << Solution().wordBreak("leetcode", dict);
	return 0;
}
