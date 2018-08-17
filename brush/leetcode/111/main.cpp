class Solution {
	public:
		void impl(TreeNode* root, int& minDepth, int currDepth) {
			if(root->left == nullptr && root->right == nullptr) {
				if(minDepth > currDepth) {
					minDepth = currDepth;
				}
				return;
			}

			if(root->left != nullptr) impl(root->left, minDepth, currDepth + 1);
			if(root->right != nullptr) impl(root->right, minDepth, currDepth + 1);
			return;
		}
		int run(TreeNode *root) {
			if(root == nullptr) return 0;
			int minDepth = std::numeric_limits<int>::max();
			impl(root, minDepth, 1);
			return minDepth;
		}
};


int main() {}
