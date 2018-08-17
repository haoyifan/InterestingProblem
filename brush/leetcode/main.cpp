#include <vector>
#include <stack>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
	public:
		/** recursion
		void impl(TreeNode* root, vector<int>& v) {
			if(root == nullptr) return;
			impl(root->left, v);
			impl(root->right, v);
			v.push_back(root->val);
		}
		vector<int> postorderTraversal(TreeNode *root) {
			vector<int> v;
			impl(root, v);
			return v;
		}
		*/

		// iterate
		vector<int> postorderTraversal(TreeNode* root) {
			vector<int> v;
			stack<TreeNode*> s;
			if(root == nullptr) return v;

			s.push(root);
			while(!s.empty()) {
				auto node = s.top(); s.pop();
				v.push_back(node->val);
				if(node->left != nullptr) s.push(node->left);
				if(node->right != nullptr) s.push(node->right);
			}

			reverse(v.begin(), v.end());
			return v;
		}
};

int main() {}
