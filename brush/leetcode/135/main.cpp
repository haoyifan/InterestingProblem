#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
	public:
		int candy(vector<int> &ratings) {
			if(ratings.size() <= 1) return ratings.size();

			vector<int> dp(ratings.size(), 1);

			for(int i = 1; i < ratings.size(); ++i) {
				if(ratings[i] > ratings[i-1])
					dp[i] = dp[i - 1] + 1;
			}

			for(int i = ratings.size() - 2; i >= 0; --i) {
				if(ratings[i] > ratings[i + 1])
					dp[i] = max(dp[i + 1] + 1, dp[i]);
			}

			return std::accumulate(dp.begin(), dp.end(), 0);
		}
};

int main() {
	vector<int> v{1,2,1};
	cout << Solution().candy(v);
}
