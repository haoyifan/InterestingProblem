#include <vector>
#include <string>
using namespace std;

class Solution {
	public:

		bool isPalindrome(const string& s) {
			return s == string(s.rbegin(), s.rend());
		}

		// dfs
		// int minCut(string s) {
		// 	if(isPalindrome(s)) return 0;
		// 	int result = std::numeric_limits<int>::max();

		// 	for(int i = 1; i <= s.size(); ++i) {
		// 		if(isPalindrome(s.substr(0, i))) {
		// 			auto sub_res = minCut(s.substr(i));
		// 			result = min(result, 1 + sub_res);
		// 		}
		// 	}
		// 	return result;
		// }

		// dp version
		int minCut(string s) {
			vector<int> dp(s.size() + 1, std::numeric_limits<int>::max());
			dp[0] = -1;
			dp[1] = 0;
			for(int i = 2; i < dp.size(); ++i) {
				dp[i] = i - 1;
			}

			for(int i = 0; i < s.size(); ++i) {
				for(int j = i + 1; j <= s.size(); ++j) {
					auto substring = s.substr(i, j - i);
					if(isPalindrome(substring))
						dp[j] = min(dp[j], dp[i] + 1);
				}
			}
			return dp.back();
		}


};

int main() {}
