#include <vector>
#include <string>
using namespace std;
class Solution {
	public:
		void impl(const string& s1, const string& s2, const string& s3, int idx1, int idx2, int idx3, vector<vector<int>>& dp) {
			// base case
			if(idx1 == (int)s1.size() && idx2 == (int)s2.size()) {
				dp[idx1][idx2] = 1;
				return;
			} else if (idx1 == (int)s1.size()) {
				if(s2[idx2] == s3[idx3]) {
					impl(s1, s2, s3, idx1, idx2+1, idx3 + 1, dp);
					dp[idx1][idx2] = std::max(dp[idx1][idx2], dp[idx1][idx2 + 1]);
				}else{
					dp[idx1][idx2] = 0;
				}
				return;
			} else if (idx2 == (int)s2.size()) {
				if(s1[idx1] == s3[idx3]) {
					impl(s1, s2, s3, idx1+1, idx2, idx3 + 1, dp);
					dp[idx1][idx2] = std::max(dp[idx1][idx2], dp[idx1+1][idx2]);
				}else{
					dp[idx1][idx2] = 0;
				}
				return;
			}
			if(dp[idx1][idx2] != -1) return;

			if(s1[idx1] != s3[idx3] && s2[idx2] != s3[idx3]) {
				dp[idx1][idx2] = 0;
				return;
			}
			if(s1[idx1] == s3[idx3]) {
				impl(s1, s2, s3, idx1+1, idx2, idx3 + 1, dp);
			} 
			if(s2[idx2] == s3[idx3]) {
				impl(s1, s2, s3, idx1, idx2+1, idx3 + 1, dp);
			}

			dp[idx1][idx2] = std::max(dp[idx1 + 1][idx2], dp[idx1][idx2 + 1]);
			return;
		}

		bool isInterleave(string s1, string s2, string s3) {
			if(s1.size() + s2.size() != s3.size()) return false;
			vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));

			impl(s1, s2, s3, 0, 0, 0, dp);

			return dp[0][0];
		}
};

int main() {}
