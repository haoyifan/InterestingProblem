#include <iostream>
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
	/*
		void impl(TreeNode* root, vector<int>& v) {
			if(root == nullptr) return;
			v.push_back(root->val);
			impl(root->left, v);
			impl(root->right, v);
		}
		vector<int> preorderTraversal(TreeNode *root) {
			vector<int> v;
			impl(root, v);
			return v;
		}
		*/
		vector<int> preorderTraversal(TreeNode *root) {
			stack<TreeNode*> s;
			vector<int> v;
			if(root == nullptr) return v;

			auto curr = root;
			while(curr != nullptr || !s.empty()) {
				while(curr != nullptr) {
					s.push(curr); 
					v.push_back(curr->val);
					curr = curr->left;
				}
				auto node = s.top(); s.pop();
				if(node->right != nullptr) curr = node->right;
			}
			return v;
		}
};

int main() {
	auto a = new TreeNode(1);
	auto b = new TreeNode(2);
	auto c = new TreeNode(3);
	a->left = b;
	a->right = c;
	auto v = Solution().preorderTraversal(a);
	for(auto i : v)
		cout << i;
}
