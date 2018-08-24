#include <vector>
#include <limits>
#include <iostream>

using namespace std;

class Solution {
	public:
		/*
		// Correct Solution, but more complicated
		int maxProfit(vector<int> &prices) {
			if(prices.size() < 2) return 0;

			vector<int> min_v(prices.size());
			vector<int> dp_pre(prices.size());

			vector<int> max_v(prices.size());
			vector<int> dp_post(prices.size());

			int curr_min = prices.front();
			min_v[0] = std::numeric_limits<int>::max();
			for(int i = 1; i < prices.size(); ++i)
				min_v[i] = std::min(min_v[i - 1], prices[i - 1]);
			for(int i = 1; i < prices.size(); ++i)
				dp_pre[i] = std::max(std::max(dp_pre[i - 1], prices[i] - min_v[i]), 0);

			int curr_max = prices.back();
			max_v[prices.size() - 1] = std::numeric_limits<int>::min();
			for(int i = prices.size() - 2; i >= 0; --i)
				max_v[i] = std::max(max_v[i + 1], prices[i + 1]);
			for(int i = prices.size() - 2; i >= 0; --i)
				dp_post[i] = std::max(std::max(dp_post[i + 1], max_v[i] - prices[i]), 0);
			
			int result = 0;
			for(int i = 0; i < prices.size(); ++i) {
				result = std::max(dp_pre[i] + dp_post[i], result);	
			}

			return result;
		}
		*/

		int maxProfit(vector<int> &prices) {
			int buy1 = std::numeric_limits<int>::min();
			int buy2 = std::numeric_limits<int>::min();
			int sell1 = 0;
			int sell2 = 0;

			for(int i = 0; i < prices.size(); ++i) {
				buy1 = std::max(buy1, -prices[i]);	
				sell1 = std::max(sell1, prices[i] + buy1);	
				buy2 = std::max(buy2, sell1-prices[i]);	
				sell2 = std::max(sell2, prices[i] + buy2);	
			}

			return sell2;
		}
};

int main() {
	vector<int> prices{3,2,6,5,0,3};
	cout << Solution().maxProfit(prices);
}
