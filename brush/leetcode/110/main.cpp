#include <cmath>
#include <algorithm>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
	public:
		bool isBalancedImpl(TreeNode* root, int& depth) {
			if(root == nullptr) {
				depth = 0;
				return true;
			}
			int leftDepth, rightDepth;

			auto leftBalanced = isBalancedImpl(root->left, leftDepth);
			auto rightBalanced = isBalancedImpl(root->right, rightDepth);

			depth = std::max(leftDepth, rightDepth) + 1;

			return leftBalanced && rightBalanced && abs(leftDepth - rightDepth) <= 1;
		}
		bool isBalanced(TreeNode *root) {
			int depth;
			return isBalancedImpl(root, depth);
		}
};

int main() {}
