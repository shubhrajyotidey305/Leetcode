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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return NULL;
        if(k==0) return head;
        
        
        ListNode *curr = head;
        int n = 0;
        while(curr->next){
            curr = curr->next;
            n++;
        }
        
        ++n;
        
        k = k%n;
        
        ListNode *curr2 = head;
        for(int i=1; i<n-k; i++){
            curr2 = curr2->next;
        }
        
        curr->next = head;
        ListNode *temp = curr2->next;
        curr2->next = NULL;
        return temp;
    }
};