#include <queue>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
	public:
		TreeNode *sortedListToBST(ListNode *head) {
			if(head == nullptr) return nullptr;
			if(head->next == nullptr) return new TreeNode(head->val);

			ListNode* fast = head->next;
			ListNode* slow = head;
			ListNode* prev = nullptr;

			while(fast != nullptr && fast->next != nullptr) {
				fast = fast->next->next;
				prev = slow;
				slow = slow->next;
			}

			TreeNode* left = nullptr, *right = nullptr;
			right = sortedListToBST(slow->next);
			if(prev != nullptr) prev->next = nullptr;
			if(slow != head) left = sortedListToBST(head);

			auto root = new TreeNode(slow->val);
			root->left = left;
			root->right = right;
			return root;
		}
};

int main () {
	auto a = new ListNode(-10);
	auto b = new ListNode(-3);
	auto c = new ListNode(0);
	auto d = new ListNode(5);
	auto e = new ListNode(9);

	a->next = b;
	b->next = c;
	c->next = d;
	d->next = e;
	e->next = nullptr;

	auto r = Solution().sortedListToBST(a);
	
	queue<TreeNode*> q;
	q.push(r);
	while(!q.empty()){
		auto c = q.front(); q.pop();
		if(c == nullptr) continue;
		cout << c->val << endl;
		q.push(c->left);
		q.push(c->right);
	}
}
