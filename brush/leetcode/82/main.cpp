struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
	public:
		ListNode *deleteDuplicates(ListNode *head) {
			ListNode* dummy = new ListNode(0);
			dummy->next = head;
			auto curr = dummy;

			while(curr->next != nullptr && curr->next->next != nullptr) {
				if(curr->next->val == curr->next->next->val) {
					auto val = curr->next->val;
					while(curr->next != nullptr && curr->next->val == val) {
						auto victim = curr->next;
						curr->next = curr->next->next;
						delete victim;
					}
				} else {
					curr = curr->next;
				}
			}
			auto res = dummy->next;
			delete dummy;
			return res;
		}
};

int main() {}
