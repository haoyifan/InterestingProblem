#include <string>
#include <vector>
#include <iostream>

using namespace std;
class Solution {
	public:
		bool isValid(string s) {
			int sum = 0;
			for(int i = 0; i < s.size(); ++i) {
				sum = sum*10 + s[i] - '0';
				if(sum < 1 || sum > 26) return false;
			}
			return true;
		}

		int numDecodings(string s) {
			if(s == string("") || s[0] == '0') return 0;
			vector<int> dp(s.size() + 1, 0);
			dp[0] = 1; dp[1] = 1;
			for(int i = 2; i <= s.size(); ++i) {
				if(isValid(s.substr(i - 1, 1))) dp[i] += dp[i - 1];
				if(isValid(s.substr(i - 2, 2))) dp[i] += dp[i - 2];
			}
			return dp.back();
		}
};

int main () {
	cout << Solution().numDecodings("01");
}
