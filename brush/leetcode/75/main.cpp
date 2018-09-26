#include <vector>
#include <algorithm>

using namespace std;
class Solution {
	public:
		void sortColors(int A[], int n) {
			int left = 0, curr = 0, right = n - 1;
			while(curr <= right) {
				if(A[curr] == 0) swap(A[left++], A[curr++]);
				else if(A[curr] == 2) swap(A[right--], A[curr]);
				else curr++;
			}
			return;
		}
};

int main() {}
