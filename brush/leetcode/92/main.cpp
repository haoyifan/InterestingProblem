#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
	public:
		ListNode *reverseBetween(ListNode *head, int m, int n) {
			auto start = m;
			ListNode* prev = nullptr;
			ListNode* first = head;
			while(--m > 0) {
				if(first == nullptr) return head;
				prev = first;
				first  = first->next;
			}

			ListNode* guard = prev;
			ListNode* curr = first;
			n = n - start;
			while(n-- >= 0) {
				auto next = curr->next;
				curr->next = guard;
				guard = curr;
				curr = next;
			}

			first->next = curr;
			if(prev != nullptr)
				prev->next = guard;
			else
				head = guard;
			return head;
		}
};

void print(ListNode* n) {

	while(n != nullptr) {
		cout << n->val << " ";	
		n = n->next;
	}

	cout << endl;
}

int main () {
	auto a = new ListNode(1);
	auto b = new ListNode(2);
	auto c = new ListNode(3);
	auto d = new ListNode(4);
	auto e = new ListNode(5);
	a->next = b;
	b->next = c;
	c->next = d;
	d->next = e;
	auto x = Solution().reverseBetween(e, 1,1);
	print(x);
}
