#include<vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
	public:
		void inorder(TreeNode* root, vector<int>& v) {
			if(root == nullptr) return;
			inorder(root->left, v);
			v.push_back(root->val);
			inorder(root->right, v);
		}
		bool isValidBST(TreeNode *root) {
			if(root == nullptr) return true;
			vector<int> v;
			inorder(root, v);
			auto curr = v.front();
			auto iter = v.begin() + 1;
			for (; iter < v.end(); ++iter) {
				if(curr >= *iter) return false;
				curr = *iter;
			}
			return true;
		}
};

int main() {}
