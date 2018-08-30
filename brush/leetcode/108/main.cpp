 #include <vector>

 using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };
 
class Solution {
	public:
		TreeNode* impl(const vector<int>& num, int low, int high) {
			if(low >= high) return nullptr;
			auto midIter = num.begin() + low + (high - low) / 2;

			auto root = new TreeNode(*midIter);
			root->left = impl(num, low, low + (high - low) / 2);
			root->right = impl(num, low + (high - low) / 2 + 1, high);
			return root;
		}
		TreeNode *sortedArrayToBST(vector<int> &num) {
			return impl(num, 0, num.size());
		}
};

int main () {
	vector<int> v{-10, -3, 0, 5, 9};
	Solution().sortedArrayToBST(v);
}
