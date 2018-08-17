#include <iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
	public:

		void separate(ListNode*& odd, ListNode*& even) {
			while(even->next != nullptr && even->next->next != nullptr) {
				even = even->next->next;
				odd = odd->next;
			}
			even = odd->next;
			odd->next = nullptr;
		}

		ListNode* reverse(ListNode* head) {
			ListNode* prev = nullptr;
			while(head) {
				auto tmp = head->next;
				head->next = prev;
				prev = head;
				head = tmp;
			}
			return prev;
		}

		void merge(ListNode* odd, ListNode* even) {
			while(odd != nullptr && even != nullptr) {
				auto oddtmp = odd->next;
				auto eventmp = even->next;

				odd->next = even;
				even->next = oddtmp;

				odd = oddtmp;
				even = eventmp;
			}
		}

		void reorderList(ListNode *head) {
			if(head == nullptr || head->next == nullptr || head->next->next == nullptr) return;

			auto odd = head;
			auto even = head;
			separate(odd, even);
			odd = head;

			even = reverse(even);

			merge(odd, even);

			return;
		}
};

int main() {
	auto a = new ListNode(1);
	auto b = new ListNode(2);
	auto c = new ListNode(3);
	auto d = new ListNode(4);
	auto e = new ListNode(5);
	a->next = b;
	b->next = c;
	c->next = d;
	d->next = e;

	Solution().reorderList(a);

	while(a) {
		cout << a->val;
		a = a->next;
	}
}
