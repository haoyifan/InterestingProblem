#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
	public:
		// backtracking
		/*
		void generate(vector<vector<int>>& res, const vector<int>& S, int idx, vector<int>& curr) {
			if(idx >= S.size()) {
				res.push_back(curr);
				return;
			}

			generate(res, S, idx+1, curr);
			curr.push_back(S[idx]);
			generate(res, S, idx+1, curr);
			curr.pop_back();
			return;
		}
		vector<vector<int> > subsets(vector<int> &S) {
			vector<vector<int>> res;
			vector<int> curr;
			generate(res, S, 0, curr);

			std::sort(res.begin(), res.end());
			res.erase(std::unique(res.begin(), res.end()), res.end());

			return res;
		}
		*/

		// dp

		void generate(unordered_map<int, vector<vector<int>>>& dp, const vector<int>& S, int idx) {
			if(idx == 0) {
				dp[idx] = std::move(vector<vector<int>>({{}}));	
				return;
			}
			generate(dp, S, idx - 1);
			auto& prev_sets = dp[idx - 1];
			vector<vector<int>> new_sets;
			for(auto& set : prev_sets) {
				auto new_set = set;
				new_set.push_back(S[idx - 1]);
				new_sets.push_back(set);
				new_sets.push_back(std::move(new_set));
			}
			dp[idx] = std::move(new_sets);
			return;
		}

		vector<vector<int> > subsets(vector<int> &S) {
			if(S.empty()) return vector<vector<int>>();

			unordered_map<int, vector<vector<int>>> dp;
			generate(dp, S, S.size());
			auto& res = dp[S.size()];
			return res;
		}
};

int main() {
	vector<int> v{1,2};
	auto x = Solution().subsets(v);

	for(auto& set : x) {
		for(auto ele : set)
			cout << ele << " ";
		cout << endl;
	}
}
