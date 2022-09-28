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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *curr = head;
        int size = 0;
        while(curr){
            curr = curr->next;
            size++;
        }
        
        if(size == 1){
            delete(head);
            return NULL;
        }
        
        if(size == n){
            ListNode *temp = head;
            head = head->next;
            delete(temp);
            return head;
        }
        
        int idx = size-n+1;
        
        curr = head;
        
        for(int i=1; i<idx-1; i++){
            curr = curr->next;
        }
        
        ListNode *temp = curr->next;
        curr->next = temp->next;
        delete(temp);
        return head;
    }
};