ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
    public:
        ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
            if(l1 == nullptr) return l2;
            if(l2 == nullptr) return l1;
            ListNode* result = nullptr;
            ListNode* prev = nullptr;

            while(l1 && l2) {
                if(l1->val < l2->val) {
                    if(result == nullptr) {
                        result = l1;
                        prev = l1;
                    } else {
                        prev->next = l1;
                        prev = prev->next;
                    }
                    l1 = l1->next;
                } else {
                    if(result == nullptr) {
                        result = l2;
                        prev = l2;
                    } else {
                        prev->next = l2;
                        prev = prev->next;
                    }
                    l2 = l2->next;
                }
            }

            if(l1)
                prev->next = l1;
            else
                prev->next = l2;
            return result;
        }
};

int main() {}
