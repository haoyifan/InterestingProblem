struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
		}
};

class Solution {
	public:
		bool impl(TreeNode* leftRoot, TreeNode* rightRoot) {
			if(leftRoot == nullptr && rightRoot == nullptr)
				return true;
			if(leftRoot == nullptr || rightRoot == nullptr)
				return false;
			return leftRoot->val == rightRoot->val && impl(leftRoot->left, rightRoot->right) && impl(leftRoot->right, rightRoot->left);
		}

		bool isSymmetrical(TreeNode* pRoot)
		{
			return impl(pRoot, pRoot);
		}

};

int main() {

}
