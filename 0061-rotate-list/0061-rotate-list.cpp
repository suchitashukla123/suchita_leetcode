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
    ListNode* findnthnode(ListNode* head, int k){
        ListNode* temp=head;
        int count=1;
        while(temp!=NULL){
            if(count==k) return temp;
            count++;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* tail=head;
        int length=1;
        while(tail->next!=NULL){
            length++;
            tail=tail->next;
        }
        if(k%length==0) return head;
        k=k%length;
        tail->next=head;
        ListNode* NewLastNode= findnthnode(head,length-k);
        head=NewLastNode->next;
        NewLastNode->next=NULL;
        return head;
    }
};