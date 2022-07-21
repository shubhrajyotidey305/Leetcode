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
#define Node ListNode
class Solution {
public:
    ListNode* reverseList(ListNode* head) {      
                
        ListNode* current = head;
        ListNode *prev = NULL, *next = NULL;
 
        while (current){           
            next = current->next;            
            current->next = prev;            
            prev = current;
            current = next;
        }
        
        return prev;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head->next == NULL || left == right)
            return head;
        
        Node *nxt = head;
        right--;
        while(right--){
            nxt = nxt->next;   
        }
        
        Node *link2 = nxt->next;
        nxt->next = NULL;
        
        Node *prev = head;
        
        if(left == 1){
            head = reverseList(prev);
            prev->next = link2;
            return head;
        }
        
        left -= 2;
        while(left--){
            prev = prev->next;
        }
        
        Node *temp = reverseList(prev->next);
        Node *dummy = prev->next;
        
        prev->next = temp;
        dummy->next = link2;
        
        return head;       
        
    }
};