#include <vector>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<TreeNode*> impl(int low, int high) {
        vector<TreeNode*> result;
        
        if(low >= high) {
            result.push_back(nullptr);
            return result;
        }
        
        for(int i = low; i < high; ++i) {
            auto leftSubtree = impl(low, i);
            auto rightSubtree = impl(i+1, high);
            for(auto leftT : leftSubtree) {
                for(auto rightT : rightSubtree) {
                    auto root = new TreeNode(i);
                    root->left = leftT;
                    root->right = rightT;
                    result.push_back(root);
                }
            }
        }
        return result;
    }
    vector<TreeNode *> generateTrees(int n) {
        if(n == 0) return vector<TreeNode*>();
        return impl(1, n + 1);
    }
};

int main() {}
