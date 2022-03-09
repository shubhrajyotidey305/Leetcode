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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        
        map<int, int> mp;
        
        ListNode *curr = head;
        
        while(curr){
            mp[curr->val]++;
            curr = curr->next;
        }
        
        curr = head;
        
        while(curr){
            if(mp[curr->val] > 1){
                curr = curr->next;
            }
            else
                break;
        }
        
        if(curr == NULL) 
            return NULL;
        
        head = curr;
        ListNode *prev = head;
        ListNode *temp = prev;      
        
        
        while(true){
            if(prev == curr){
                curr = curr->next;                
            }
            
            if(curr && mp[curr->val] > 1){
                curr = curr->next;
            }
            else{                
                prev->next = curr;
                if(curr == NULL)
                    break;
                prev = prev->next;
                
                curr = curr->next;
            }                
            
        }
        return temp;
    }
};