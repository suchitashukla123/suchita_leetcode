/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;   // to keep track of the last node in new list
        ListNode* p = head;
        int count = 0;

        while (p != NULL) {
            if (p->val != 0) {
                count += p->val;
            } else {
                if (count > 0) {   // avoid first zero
                    tail->next = new ListNode(count);
                    tail = tail->next;
                    count = 0;
                }
            }
            p = p->next;
        }

        return dummy->next;
    }
};
