#include <vector>

using namespace std;

class Solution {
	public:
		vector<int> getRow(int rowIndex) {
			if(rowIndex == 0) return vector<int>({1});
			if(rowIndex == 1) return vector<int>({1, 1});
			vector<int> curr{1,1};
			for(int i = 1; i < rowIndex; ++i) {
				vector<int> next(curr.size() + 1);
				next.front() = 1;
				next.back() = 1;
				for(int j = 1; j <= i; ++j) {
					next[j] = curr[j - 1] + curr[j];
				}
				curr.swap(next);
			}
			return curr;
		}
};

int main() {}
