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
		void impl(vector<vector<int>>& result, vector<int>& curr, TreeNode* root, int& sum, int curr_sum) {
			curr.push_back(root->val);
			curr_sum += root->val;

			if(root->left == nullptr && root->right == nullptr) {
				if(curr_sum == sum)
					result.push_back(curr);
				goto end;
			}

			if(root->left != nullptr) impl(result, curr, root->left, sum, curr_sum);
			if(root->right != nullptr) impl(result, curr, root->right, sum, curr_sum);

		end:
			curr.pop_back();
			return;
		}

		vector<vector<int> > pathSum(TreeNode *root, int sum) {
			vector<vector<int>> result;
			if(root == nullptr) return result;

			vector<int> curr;

			impl(result, curr, root, sum, 0);

			return result;
		}
};

int main() {}
