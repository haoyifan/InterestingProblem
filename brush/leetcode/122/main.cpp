#include <vector>
#include <limits>
using namespace std;

class Solution {
	public:
		int maxProfit(vector<int> &prices) {
			if(prices.size() < 2) return 0;
			int result = 0;
			int last_minimum = prices[0];

			for(int i = 1; i < prices.size(); ++i){
				if(prices[i] < last_minimum) last_minimum = prices[i];
				else {
					if(i+1 < prices.size() && prices[i + 1] < prices[i]) {
						result += (prices[i] - last_minimum);
						last_minimum = prices[i];
					} else if (i+1 >= prices.size() && prices[i] > last_minimum)
						result += (prices[i] - last_minimum);
				}
			}

			return max(result, 0);
		}
};

int main() {}
