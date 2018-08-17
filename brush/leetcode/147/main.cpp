#include <iostream>

using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:

		ListNode *insertionSortList(ListNode *head) {
			if(head == nullptr || head->next == nullptr) return head;

			auto curr = head->next; // current element that we are working on
			auto prev = head; // element that's ahead of curr

			while(curr != nullptr) {
				// curr element should be placed before head
				if(curr->val <= head->val) {
					prev->next = curr->next;
					curr->next = head;
					head = curr;
					curr = prev->next;
				} else {
					ListNode* innerPrev = head;
					auto nextElem = head->next;
					while(nextElem != curr && curr->val > nextElem->val) {
						nextElem = nextElem->next;
						innerPrev = innerPrev->next;
					}
					if(nextElem != curr) {
						prev->next = curr->next;
						innerPrev->next = curr;
						curr->next = nextElem;
						curr = prev->next;
					} else {
						prev = prev->next;
						curr = curr->next;
					}
				}
			}

			return head;
		}
};


int main() {
	Solution s;
	auto a = new ListNode(-1);
	auto b = new ListNode(5);
	auto c = new ListNode(3);
	auto d = new ListNode(4);
	auto e = new ListNode(0);
	a->next = b;
	b->next = c;
	c->next = d;
	d->next = e;
	auto result = s.insertionSortList(a);

	while(result) {
		cout << result->val << endl;	
		result = result->next;
	}
}
