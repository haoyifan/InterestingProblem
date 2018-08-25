struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
	public:
		bool impl(TreeNode* left, TreeNode* right) {
			if(left == nullptr && right == nullptr) return true;
			if(left == nullptr || right == nullptr) return false;

			return left->val == right->val && impl(left->left, right->right) && impl(left->right, right->left);
		}
		bool isSymmetric(TreeNode *root) {
			return impl(root, root);
		}
};

int main() {}
