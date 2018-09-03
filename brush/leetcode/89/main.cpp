#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
	public:
		void impl(vector<int>& res, unordered_set<int>& s, int curr, int n) {
			// check
			if(s.find(curr) != s.end())
				return;

			res.push_back(curr);
			s.insert(curr);
			for(int i = 0; i < n; ++i) {
				curr ^= (1 << i);
				impl(res, s, curr, n);
				curr ^= (1 << i);
			}
			return;
		}
		vector<int> grayCode(int n) {
			vector<int> res;
			unordered_set<int> s;
			int curr = 0;
			impl(res, s, curr, n);
			return res;
		}
};

int main() {}
