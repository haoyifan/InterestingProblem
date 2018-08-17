#include <iostream>
#include <cassert>

using namespace std;

struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

	}
};

TreeLinkNode* GetNext(TreeLinkNode* pNode)
{
	if(pNode == nullptr)
		return nullptr;

	// right child is not nullptr
	if(pNode->right != nullptr) {
		auto curr = pNode->right;
		while(curr->left != nullptr) {
			curr = curr->left;
		}
		return curr;
	}

	// right child is nullptr. So goes to parent
	while(pNode->next != nullptr) {
		if(pNode->next->left == pNode)
			return pNode->next;
		else if(pNode->next->right == pNode) {
			pNode = pNode->next;
		}
	}

	return nullptr;
}

int main() {
	auto a = new TreeLinkNode(1);
	auto b = new TreeLinkNode(2);
	auto c = new TreeLinkNode(3);
	auto d = new TreeLinkNode(4);
	a->left = b;
	b->next = a;
	a->right = c;
	c->next = a;
	b->left= d;
	d->next = b;

	assert(GetNext(a)->val == c->val);

	assert(GetNext(b)->val == a->val);

	assert(GetNext(c) == nullptr);

	cout << "PASSED" << endl;
}
