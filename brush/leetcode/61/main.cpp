struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
	public:
		int sizer(ListNode* head) {
			int result = 0;
			while(head != nullptr) {
				result++;
				head = head->next;
			}
			return result;
		}

		ListNode *rotateRight(ListNode *head, int k) {
			if(head == nullptr || head->next == nullptr || k == 0) return head;
			k = k % sizer(head);
			ListNode* fast = head;
			ListNode* slow = head;

			while(k-- > 0) {
				fast = fast->next;
				if(fast == nullptr) return head;
			}
			while(fast->next != nullptr) {
				fast = fast->next;
				slow = slow->next;
			}
			ListNode* newHead = slow->next;
			if(newHead == nullptr) return head;
			slow->next = nullptr;
			fast->next = head;
			head = newHead;
			return newHead;
		}
};

int main() {}
