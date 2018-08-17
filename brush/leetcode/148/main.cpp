#include <iostream>

using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		ListNode* findMiddle(ListNode* head) {
			if(head == nullptr) return head;
			ListNode* fast = head;
			ListNode* slow = head;

			while(fast->next != nullptr && fast->next->next != nullptr) {
				fast = fast->next->next;
				slow = slow->next;
			}

			return slow;
		}
		ListNode* merge(ListNode* list1, ListNode* list2) {
			if(list1 == nullptr && list2 == nullptr) return nullptr;
			if(list1 == nullptr) return list2;
			if(list2 == nullptr) return list1;

			ListNode* result = nullptr;
			ListNode* curr = nullptr;
			while(list1 && list2) {
				if(list1->val > list2->val) {
					if(curr == nullptr) {
						curr = list2;
						result = curr;
					} else {
						curr->next = list2;
						curr = curr->next;
					}
					list2 = list2->next;
				} else {
					if(curr == nullptr) {
						curr = list1;
						result = curr;
					} else {
						curr->next = list1;
						curr = curr->next;
					}
					list1 = list1->next;
				}
			}
			if(list1 != nullptr) {
				curr->next = list1;
			}
			if(list2 != nullptr) {
				curr->next = list2;
			}

			return result;
		}
		ListNode *sortList(ListNode *head) {
			if(head == nullptr || head->next == nullptr) return head;
			// find the middle node
			auto middle = findMiddle(head);

			// mergeSort two sublists
			auto secondList = middle->next;
			middle->next = nullptr;
			auto list1 = sortList(secondList);
			auto list2 = sortList(head);

			// merge two lists
			return merge(list1, list2);
		}
};

int main() {
	Solution s;
	auto a = new ListNode(2);
	auto b = new ListNode(1);
	auto c = new ListNode(3);
	a->next = b;
	b->next = c;
	auto result = s.sortList(a);

	while(result) {
		cout << result->val << endl;	
		result = result->next;
	}
}
