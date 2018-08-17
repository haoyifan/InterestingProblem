// print a binary tree into multiple rows

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
		vector<vector<int> > Print(TreeNode* pRoot) {
			vector<vector<int>> result;
			queue<TreeNode*> currLayer;
			queue<TreeNode*> nextLayer;
			currLayer.push(pRoot);
			while(!currLayer.empty()) {
				vector<int> layer;
				while(!currLayer.empty()) {
					auto node = currLayer.front(); currLayer.pop();
					if(node != nullptr) {
						nextLayer.push(node->left);
						nextLayer.push(node->right);
						layer.push_back(node->val);
					}
				}
				swap(currLayer, nextLayer);
				if(!layer.empty())
					result.push_back(std::move(layer));
			}
			return result;
		}
};

int main() { }
