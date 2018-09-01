#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
	public:
		vector<vector<int> > levelOrder(TreeNode *root) {
			queue<TreeNode*> q;
			q.push(root);
			vector<vector<int>> result;
			while(!q.empty()) {
				auto size = q.size();
				vector<int> layer;
				while(size-- > 0) {
					auto curr = q.front(); q.pop();
					if(curr == nullptr) continue;
					layer.push_back(curr->val);
					q.push(curr->left);
					q.push(curr->right);
				}
				if(!layer.empty()) result.push_back(std::move(layer));
			}
			return result;
		}
};

int main() {}
