struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
	public:
		ListNode *deleteDuplicates(ListNode *head) {
			auto curr = head;
			while(curr != nullptr && curr->next != nullptr) {
				if(curr->next != nullptr && curr->next->val == curr->val) {
					auto victim = curr->next;
					curr->next = curr->next->next;
					delete victim;
				} else
					curr = curr->next;
			}
			return head;
		}
};

int main() {}
