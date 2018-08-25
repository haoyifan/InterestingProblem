#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		// dp[i][j] means how many subsequences match between
		// S[0, i) and T[0, j). Transition equations:
		// if S[i-1] != T[j-1], dp[i][j] = dp[i-1][j]
		// if S[i-1] == T[j-1], dp[i][j] = dp[i-1][j-1] + dp[i-1][j]
		int numDistinct(string S, string T) {
			vector<vector<int>> dp(S.size() + 1, vector<int>(T.size() + 1, 0));

			for(int i = 0; i < S.size(); ++i)
					dp[i][0] = 1;

			for(int i = 1; i <= S.size(); ++i)
				for(int j = 1; j <= T.size(); ++j)
					if(S[i-1] != T[j-1]) dp[i][j] = dp[i-1][j];
					else dp[i][j] = dp[i-1][j-1] + dp[i-1][j];

			return dp.back().back();
		}
};

int main() {
	string S = "ccc";
	string T = "c";

	cout << Solution().numDistinct(S, T);
}
