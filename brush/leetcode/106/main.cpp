#include <vector>
#include <algorithm>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };
 
class Solution {
	private:
		TreeNode* _construct(const vector<int>& inorder, const vector<int>& postorder, int inLow, int inHigh, int postLow, int postHigh) {
			if(inLow >= inHigh || postLow >= postHigh) return nullptr;

			auto curr = postorder[postHigh - 1];
			auto inRootIter = std::find(inorder.begin(), inorder.end(), curr);
			auto distance = inRootIter - inorder.begin();
			auto root = new TreeNode(curr);
			root->left = _construct(inorder, postorder, inLow, distance, postLow, postLow + distance - inLow);
			root->right = _construct(inorder, postorder, distance+1, inHigh, postLow+distance - inLow, postHigh - 1);

			return root;
		}

	public:
		TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
			auto size = inorder.size();
			return _construct(inorder, postorder, 0, size, 0, size);
		}
};

int main() {}
