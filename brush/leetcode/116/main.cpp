#include <queue>

using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};
class Solution {
	public:
		void connect(TreeLinkNode *root) {
			if(root == nullptr) return;
			queue<TreeLinkNode*> q;
			q.push(root);
			while(!q.empty()) {
				auto size = q.size();
				while(size-- > 0) {
					auto x = q.front(); q.pop();
					if(x->left != nullptr) q.push(x->left);
					if(x->right != nullptr) q.push(x->right);
					if(size > 0)
						x->next = q.front();
					else
						x->next = nullptr;
				}
			}
			return;
		}
};

int main() {}
