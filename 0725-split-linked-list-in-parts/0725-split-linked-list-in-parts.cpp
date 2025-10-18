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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result(k, nullptr);
        // Step 1: Get length of the list
        int n = 0;
        ListNode* curr = head;
        while (curr) {
            n++;
            curr = curr->next;
        }
        
        // Step 2: Determine base size and extras
        int partSize = n / k;
        int extra = n % k;
        
        // Step 3: Split the list
        curr = head;
        for (int i = 0; i < k && curr; i++) {
            result[i] = curr;
            int currentPartSize = partSize + (extra-- > 0 ? 1 : 0);
            
            // Move to the end of this part
            for (int j = 1; j < currentPartSize; j++) {
                if (curr) curr = curr->next;
            }
            
            // Cut and move to the next part
            if (curr) {
                ListNode* nextPart = curr->next;
                curr->next = nullptr;
                curr = nextPart;
            }
        }
        
        return result;
    }
};
