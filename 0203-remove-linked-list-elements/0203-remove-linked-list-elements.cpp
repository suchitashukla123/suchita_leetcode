class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while (head != nullptr && head->val == val) {
            head = head->next;
        }
        if (!head) return nullptr;

        ListNode* p = head;
        ListNode* q = nullptr;

        while (p != nullptr) {
            if (p->val == val) {
                q->next = p->next;
                p = q->next;
            } else {
                q = p;
                p = p->next;
            }
        }
        return head;
    }
};

