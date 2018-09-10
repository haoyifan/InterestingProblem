#include <vector>
using namespace std;

class Solution {
	public:
		void impl(vector<vector<int>>& sol, vector<int>& curr, int n, int k, int idx) {
			if(curr.size() == k) {
				sol.push_back(curr);
				return;
			}

			for(int i = idx; i <=n; ++i) {
				curr.push_back(i);
				impl(sol, curr, n, k, i+1);
				curr.pop_back();
			}

			return;
		}
		vector<vector<int> > combine(int n, int k) {
			vector<vector<int>> sol;
			vector<int> curr;
			for(int i = 1; i <= n; ++i) {
				curr.push_back(i);
				impl(sol, curr, n, k, i+1);
				curr.pop_back();
			}
			return sol;
		}
};

int main() {}
