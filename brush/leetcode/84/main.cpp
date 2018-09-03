#include <vector>
#include <stack>
using namespace std;
class Solution {
	public:
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
};

int main() {}
