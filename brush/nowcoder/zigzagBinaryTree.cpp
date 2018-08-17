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
			int layer = 1;
			vector<vector<int>> result;
			stack<TreeNode*> oddS;
			stack<TreeNode*> evenS;
			oddS.push(pRoot);

			while(!oddS.empty() || !evenS.empty()) {
				vector<int> v;
				if(layer % 2 == 1) { // odd layer
					while(!oddS.empty()) {
						auto curr = oddS.top(); oddS.pop();
						if(curr != nullptr) {
							v.push_back(curr->val);
							evenS.push(curr->left);
							evenS.push(curr->right);
						}
					}
				} else { // even layer
					while(!evenS.empty()) {
						auto curr = evenS.top(); evenS.pop();
						if(curr != nullptr) {
							v.push_back(curr->val);
							oddS.push(curr->right);
							oddS.push(curr->left);
						}
					}
				}                
				if(!v.empty())
					result.push_back(std::move(v));
				layer++;
			}
			return result;
		}
};

int main() { }
