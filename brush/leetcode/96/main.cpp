class Solution {
	private:
		int impl(int low, int high) {
			if(low >= high) {
				return 1;
			}

			int sum = 0;
			for(int i = low; i < high; ++i) {
				auto leftSubtreeNum = impl(low, i);
				auto rightSubtreeNum = impl(i+1, high);
				sum += leftSubtreeNum * rightSubtreeNum;
			}
			return sum;
		}
	public:
		int numTrees(int n) {
			return impl(1, n + 1);
		}
};

int main() {}
