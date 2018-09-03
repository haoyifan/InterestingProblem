struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
	public:
		ListNode *partition(ListNode *head, int x) {
			ListNode* curr = head;
			ListNode* prev = nullptr;
			while(curr) {
				if(curr->val >= x) {
					auto canary = curr->next;
					auto canary_prev = curr;
					while(canary && canary->val >= x) {
						canary_prev = canary;
						canary = canary->next;
					}
					if(canary == nullptr) return head;
					// check prev
					if(prev) {
						prev->next = canary;
						prev = canary;
					} else {
						head = prev = canary;
					}
					canary_prev->next = canary->next;
					canary->next = curr;
				} else {
					prev = curr;
					curr = curr->next;
				}
			}
			return head;
		}
};

int main() {}

// better solution: have two linked list to keep track of two partitions,
// then link together.
