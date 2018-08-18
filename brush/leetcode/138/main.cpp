struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(nullptr), random(nullptr) {}
};

class Solution {
	public:
		RandomListNode *copyRandomList(RandomListNode *head) {

			RandomListNode* result = nullptr;

			auto curr = head;
			while(curr != nullptr) {
				auto newNode = new RandomListNode(curr->label);
				newNode->next = curr->next;
				curr->next = newNode;
				curr = curr->next->next;
			}

			curr = head;
			while(curr) {
				if(curr->random != nullptr)
					curr->next->random = curr->random->next;
				else
					curr->next->random = nullptr;
				curr = curr->next->next;
			}

			while(head) {
				auto nextHead = head->next->next;
				if(result == nullptr)
					result = head->next;
				head->next->next = nextHead == nullptr ? nullptr : nextHead->next;
				head->next = nextHead;
				head = nextHead;
			}

			return result;
		}
};

int main() {}
