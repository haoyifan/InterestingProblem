#include <algorithm>
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
	private:
		int result;
	public:
		int impl(TreeNode* root) {
			if(root == nullptr) return 0;
			auto left = std::max(0, impl(root->left));
			auto right = std::max(0, impl(root->right));
			result = std::max(left + right + root->val, result);
			return std::max(left, right) + root->val;
		}

		int maxPathSum(TreeNode *root) {
			result = std::numeric_limits<int>::min();
			impl(root);
			return result;
		}
};

int main() {}
