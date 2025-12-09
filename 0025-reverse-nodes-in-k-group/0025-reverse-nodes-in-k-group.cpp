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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode *prevGroupEnd = &dummy;
        ListNode *curr = head;

        while (true) {
            // Check if there are at least k nodes left
            ListNode* node = curr;
            for (int i = 0; i < k; i++) {
                if (!node) return dummy.next;
                node = node->next;
            }

            // Reverse k nodes
            ListNode* prev = node;
            ListNode* next = nullptr;
            ListNode* start = curr;
            for (int i = 0; i < k; i++) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            // Connect previous group to current reversed group
            prevGroupEnd->next = prev;
            prevGroupEnd = start;
        }
    }
};

