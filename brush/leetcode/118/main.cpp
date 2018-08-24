#include <vector>
#include <iostream>
using namespace std;

class Solution {
	public:
		vector<vector<int> > generate(int numRows) {
			vector<vector<int>> result;
			if(numRows == 0) return result;
			result.push_back(std::move(vector<int>({1}))); 
			if(numRows == 1) return result;
			result.push_back(std::move(vector<int>({1, 1}))); 
			if(numRows == 2) return result;

			vector<int> curr = result.back();
			for(int i = 2; i < numRows; ++i) {
				vector<int> next(curr.size() + 1);
				next.front() = 1;
				next.back() = 1;
				for(int j = 1; j < i; ++j) {
					next[j] = curr[j - 1] + curr[j];
				}
				result.push_back(std::move(next));
				curr = result.back();
			}
			return result;
		}
};


int main() {
	auto x = Solution().generate(5);
	for(auto& v: x) {
		for(auto i : v)
			cout << i << " ";
		cout << endl;
	}
}
