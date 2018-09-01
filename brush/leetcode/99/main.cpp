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
        TreeNode* lastNode;
        TreeNode* firstError;
        TreeNode* secondError;
public:

    void dfs(TreeNode* root) {
        if(root == nullptr) return;
        dfs(root->left);
        if(lastNode != nullptr && lastNode->val > root->val) {
            if(firstError == nullptr) firstError = lastNode;
            secondError = root;
        }
        lastNode = root;
        dfs(root->right);
    }
    void recoverTree(TreeNode *root) {
        lastNode = firstError = secondError = nullptr;
        dfs(root);
        if(firstError != nullptr && secondError != nullptr) std::swap(firstError->val, secondError->val);
        return;
    }
};

int main () {
	auto a = new TreeNode(1);
	auto b = new TreeNode(3);
	auto c = new TreeNode(2);
	a->left = b;
	b->right = c;
	Solution().recoverTree(a);
}
