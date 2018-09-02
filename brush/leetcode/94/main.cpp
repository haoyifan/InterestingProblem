#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
	public:
		void inorder(TreeNode* root, vector<int>& result) {
			if(root == nullptr) return;
			inorder(root->left, result);
			result.push_back(root->val);
			inorder(root->right, result);
			return;
		}
		vector<int> inorderTraversal(TreeNode *root) {
			vector<int> result;
			inorder(root, result);
			return result;
		}
};

int main () {}
