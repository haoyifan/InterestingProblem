 #include <queue>
 #include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
 
class Solution {
#define YF_LEFT true
#define YF_RIGHT false
	public:
		vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
			vector<vector<int>> result;
			deque<TreeNode*> q;
			q.push_back(root);
			bool dir = YF_LEFT;
			while(!q.empty()) {
				vector<int> layer;
				deque<TreeNode*> tmp;
				while(!q.empty()) {
					auto curr = q.back(); q.pop_back();
					if(curr == nullptr) continue;
					layer.push_back(curr->val);
					if(dir == YF_RIGHT) {
						tmp.push_back(curr->right);
						tmp.push_back(curr->left);
					}
					else {
						tmp.push_back(curr->left);
						tmp.push_back(curr->right);
					}
				}
				dir = !dir;
				q.swap(tmp);
				if(!layer.empty()) result.push_back(std::move(layer));
			}
			return result;
		}
};

int main() {}
