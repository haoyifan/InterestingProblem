 #include <algorithm>

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };
 
class Solution {
	public:
		int impl(TreeNode* root) {
			if(root == nullptr) return 0;
			return std::max(impl(root->left), impl(root->right)) + 1;
		}
		int maxDepth(TreeNode *root) {
			return impl(root);
		}
};

int main() {}
