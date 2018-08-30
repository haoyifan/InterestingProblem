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
		TreeNode* _construct(const vector<int>& preorder, const vector<int>& inorder, int preLow, int preHigh, int inLow, int inHigh) {
			if(preLow >= preHigh || inLow >= inHigh) return nullptr;
			auto currVal = preorder[preLow];
			auto inRootIter = std::find(inorder.begin(), inorder.end(), currVal);
			auto distance = inRootIter - inorder.begin();
			auto root = new TreeNode(currVal);
			root->left = _construct(preorder, inorder, preLow+1, preLow + distance - inLow + 1, inLow, distance);
			root->right = _construct(preorder, inorder, preLow + distance - inLow + 1, preHigh ,distance + 1, inHigh);
			return root;
		}
	public:
		TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
			auto size = preorder.size();
			return _construct(preorder, inorder, 0, size, 0, size);
		}
};

int main() {}
