 #include <vector>
 #include <queue>
 #include <algorithm>
 #include <memory>
 using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };
 
class Solution {
	public:
		vector<vector<int> > levelOrderBottom(TreeNode *root) {
			queue<TreeNode*> q;
			q.push(root);
			vector<vector<int>> result;
			while(!q.empty()) {
				auto size = q.size();
				vector<int> layer;
				while(size--) {
					auto curr = q.front(); q.pop();
					if(curr == nullptr) continue;
					layer.push_back(curr->val);
					q.push(curr->left);
					q.push(curr->right);
				}
				if(!layer.empty()) result.push_back(std::move(layer));
			}
			std::reverse(result.begin(), result.end());
			return result;
		}
};

int main() {}
