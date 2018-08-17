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
		TreeNode* impl(TreeNode* root, const int k, int& no) {
			if(root == nullptr)
				return nullptr;

			if(root->left == nullptr && root->right == nullptr) {
				no++;
				if(no == k)
					return root;
				else
					return nullptr;
			}
			auto leftAns = impl(root->left, k, no);
			if(leftAns != nullptr)
				return leftAns;

			no++;
			if(no == k)
				return root;
			else
				return impl(root->right, k, no);

			return nullptr;
		}

		TreeNode* KthNode(TreeNode* pRoot, int k)
		{
			int no = 0;
			return impl(pRoot, k, no);
		}
};

int main() {}
