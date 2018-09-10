#include <iostream>
class Solution {
	public:
		bool search(vector<int>& nums, int target) {
			return _impl(nums, 0, nums.size(), target);
		}

		bool _impl(vector<int>& A, int low, int high, int target) {
			if(low >= high || (low+1 == high && A[low] != target)) return false;
			if(low+1 == high && A[low] == target) return true;

			int mid = low + ((high - low) >> 1);

			if(A[low] < A[high - 1]) {
				if(A[mid] > target)
					return _impl(A, low, mid, target);
				else if (A[mid] < target)
					return _impl(A, mid, high, target);
				else
					return true;
			} else {
				return _impl(A, low, mid, target) || _impl(A, mid, high, target);
			}
			return false;
		}
};

int main() {
	int arr[] {1, 1, 3, 1};
	std::cout << Solution().search(arr, sizeof(arr), 3);
	return 0;
}
