struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
	public:
		bool impl(TreeNode* root, int& sum, int curr_sum) {
			curr_sum += root->val;
			if(root->left == nullptr && root->right == nullptr) {
				if(curr_sum == sum)
					return true;
				return false;
			}
			bool leftExist, rightExist;
			leftExist = rightExist = false;
			if(root->left != nullptr) leftExist = impl(root->left, sum, curr_sum);
			if(root->right != nullptr) rightExist = impl(root->right, sum, curr_sum);

			return leftExist || rightExist;
		}

		bool hasPathSum(TreeNode *root, int sum) {
			if(root == nullptr) return false;
			return impl(root, sum, 0);
		}
};

int main() {}
