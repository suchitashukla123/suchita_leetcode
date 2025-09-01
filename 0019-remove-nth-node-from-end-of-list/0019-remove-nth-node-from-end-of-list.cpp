/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };**/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return nullptr;

        ListNode* p = head;
        ListNode* q = NULL;
        int size = 0;

        
        while (p != NULL) {
            p = p->next;
            size++;
        }

    
        if (n == size) {
            ListNode* temp = head->next;
            delete head;  
            return temp;
        }

        p = head;
        for (int i = 1; i <= size - n; i++) {
            q = p;
            p = p->next;
        }

        q->next = p->next;
        delete p;

        return head;
    }
};
