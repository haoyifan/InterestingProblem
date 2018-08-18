struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
	public:
		bool hasCycle(ListNode *head) {
			if(head == nullptr || head->next == nullptr) return false;

			auto fast = head;
			auto slow = head;
			while(fast != nullptr && fast->next != nullptr) {
				fast = fast->next->next;
				slow = slow->next;
				if(fast == slow)
					break;
			}
			if(fast == nullptr || fast->next == nullptr)
				return false;

			return true;
		}
};

int main() {}
