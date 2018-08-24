#include <vector>
#include <limits>

using namespace std;

class Solution {
	public:
		int maxProfit(vector<int> &prices) {
			if(prices.size() < 2) return 0;
			vector<int> min_v(prices.size());
			min_v[0] = std::numeric_limits<int>::max();
			int result = std::numeric_limits<int>::min();

			for(int i = 1; i < prices.size(); ++i)
				min_v[i] = min(min_v[i - 1], prices[i - 1]);
			for(int i = 0; i < prices.size(); ++i)
				result = max(result, prices[i] - min_v[i]);

			return max(result, 0);
		}
};

int main() {}
