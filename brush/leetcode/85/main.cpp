#include <vector>
#include <stack>
using namespace std;

class Solution {
	private:
		// based on question 84
		int largestRectangleArea(vector<int> &height) {
			stack<int> s;
			int area = 0;
			for(auto i : height) {
				if(s.empty() || i > s.top())
					s.push(i);
				else {
					int cnt = 1;
					while(!s.empty() && s.top() > i) {
						auto curr = s.top(); s.pop();
						area = std::max(area, curr * cnt++);
					}
					while(cnt-- > 0) {
						s.push(i);
					}
				}
			}
			int cnt = 1;
			while(!s.empty()) {
				auto curr = s.top(); s.pop();
				area = std::max(area, curr * cnt++);
			}
			return area;
		}
	public:
		int maximalRectangle(vector<vector<char> > &matrix) {
			if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
			auto x = matrix.size();
			auto y = matrix[0].size();
			int area = 0;
			for(int i = 0; i < x; ++i) {
				vector<int> height(y, 0);
				for(int j = 0; j < y; ++j) {
					int k = i;
					while(k >= 0 && matrix[k][j] == '1') {
						height[j]++;
						k--;
					}
				}
				area = std::max(area, largestRectangleArea(height));
			}
			return area;
		}

		// #define YF_RIGHT false
		// #define YF_DOWN true
		// 	public:
		// 		void extend(pair<int, int> leftup, pair<int, int> rightdown, bool dir, int& area, int x, int y, const vector<vector<char>>& matrix) {
		// 			// dummy check
		// 			if(rightdown.first >= x || rightdown.second >= y) return;

		// 			if(dir == YF_RIGHT) {
		// 				for(int i = leftup.first; i <= rightdown.first; ++i) {
		// 					if(matrix[i][rightdown.second] == '0') return;
		// 				}
		// 			} else if(dir == YF_DOWN) {
		// 				for(int i = leftup.second; i <= rightdown.second; ++i) {
		// 					if(matrix[rightdown.first][i] == '0') return;
		// 				}
		// 			}
		// 			int newArea = (rightdown.second - leftup.second + 1) * (rightdown.first - leftup.first + 1);
		// 			area = std::max(area, newArea);
		// 			extend(leftup, pair<int, int>(rightdown.first, rightdown.second+1), YF_RIGHT, area, x, y, matrix);
		// 			extend(leftup, pair<int, int>(rightdown.first+1, rightdown.second), YF_DOWN, area, x ,y, matrix);
		// 			return;
		// 		}
		// 		int maximalRectangle(vector<vector<char> > &matrix) {
		// 			if(matrix.size() == 0) return 0;
		// 			int area = 0;
		// 			auto x = matrix.size();
		// 			auto y = matrix[0].size();
		// 			for(int i = 0; i < matrix.size(); ++i) 
		// 				for(int j = 0; j < matrix[0].size(); ++j) 
		// 					if(matrix[i][j] == '1') 
		// 						extend(pair<int, int>(i, j), pair<int, int>(i, j), YF_RIGHT, area, x, y, matrix);

		// 			return area;
		// 		}
};

int main() {
	vector<vector<char>> v{{'1'}};

	Solution().maximalRectangle(v);
}
