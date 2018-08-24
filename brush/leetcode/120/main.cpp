#include <vector>
#include <limits>

using namespace std;
class Solution {
	private:
		void impl(vector<vector<int>>& dp, const vector<vector<int>>& triangle, int layer, int idx, int curr, int& result) {
			if(layer >= triangle.size()) {
				result = std::min(curr, result);
				return;
			}

			curr += triangle[layer][idx];

			if(dp[layer][idx] < curr) return;

			dp[layer][idx] = curr;

			impl(dp, triangle, layer + 1, idx, curr, result);
			impl(dp, triangle, layer + 1, idx + 1, curr, result);

			return;
		}

	public:
		int minimumTotal(vector<vector<int> > &triangle) {
			int result = std::numeric_limits<int>::max();
			vector<vector<int>> dp(triangle.size(), vector<int>(triangle.back().size(), std::numeric_limits<int>::max()));
			impl(dp, triangle, 0, 0, 0, result);
			return result;
		}
};

int main() {}
