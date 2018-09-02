#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
	public:
		void impl(const vector<int>& S, int idx, vector<vector<int>>& result, vector<int>& curr) {
			if(idx >= (int)S.size()) {
				result.push_back(curr);
				return;
			}
			impl(S, idx+1, result, curr);
			curr.push_back(S[idx]);
			impl(S, idx+1, result, curr);
			curr.pop_back();
			return;
		}

		vector<vector<int> > subsetsWithDup(const vector<int> &S) {
			vector<vector<int>> result;
			vector<int> curr;
			impl(S, 0, result, curr);
			std::for_each(result.begin(), result.end(), [](auto& v) {std::sort(v.begin(), v.end());});
			std::sort(result.begin(), result.end());
			result.erase(std::unique(result.begin(), result.end()), result.end());
			return result;
		}
};


int main() {
	vector<int> input{4,1,0};
	auto r = Solution().subsetsWithDup(input);
	for(auto& v : r) {
		for_each(v.begin(), v.end(), [](auto& ele) {cout << ele << " ";});
		cout << endl;
	}
}
