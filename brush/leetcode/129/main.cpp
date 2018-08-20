struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
	public:
		void impl(TreeNode* root, int& sum, int curr) {
			if(root->left == nullptr && root->right == nullptr) {
				sum += curr * 10 + root->val;
				return;
			}


			curr = curr * 10 + root->val;

			if(root->left != nullptr) impl(root->left, sum, curr);
			if(root->right != nullptr) impl(root->right, sum, curr);
		}
		int sumNumbers(TreeNode *root) {
			if(root == nullptr) return 0;
			int sum = 0;
			int curr = 0;
			impl(root, sum, curr);
			return sum;
		}
};

int main() {}
