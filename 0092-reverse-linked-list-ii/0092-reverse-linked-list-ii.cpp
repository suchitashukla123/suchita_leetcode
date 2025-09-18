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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        // Step 1: Create dummy node before head
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Step 2: Move 'prev' to node before 'left'
        ListNode* prev = dummy;
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // Step 3: Reverse sublist [left, right]
        ListNode* curr = prev->next; 
        ListNode* nxt = nullptr;

        for (int i = 0; i < right - left; i++) {
            nxt = curr->next;
            curr->next = nxt->next;
            nxt->next = prev->next;
            prev->next = nxt;
        }

        return dummy->next;
    }
};

