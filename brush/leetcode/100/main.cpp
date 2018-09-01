struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
	public:
		bool impl(TreeNode* p, TreeNode* q) {
			if(p==nullptr && q==nullptr) return true;
			if(p==nullptr || q==nullptr) return false;
			return p->val == q->val && impl(p->left, q->left) && impl(p->right, q->right);
		}
		bool isSameTree(TreeNode *p, TreeNode *q) {
			return impl(p, q);
		}
};


int main() {}
