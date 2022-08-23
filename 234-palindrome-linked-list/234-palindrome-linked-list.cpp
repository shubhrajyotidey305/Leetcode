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
    
    ListNode *middle(ListNode *head){
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(slow->next && fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    bool isPalindrome(ListNode* head) {
        Node *mid = middle(head);
        
        Node *rev = reverseList(mid->next);
        mid->next = NULL;
        
        Node *curr = head;
        while(rev){
            if(curr->val != rev->val)
                return false;
            curr = curr->next;
            rev = rev->next;
        }
        return true;
        
    }
};