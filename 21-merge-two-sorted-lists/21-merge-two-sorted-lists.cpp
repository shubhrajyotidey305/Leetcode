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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        Node *merged = new Node(1);
        Node *temp = new Node(1);
        
        merged = temp;
        
        while(head1 && head2){
            if(head1->val<=head2->val){
                temp->next = head1;
                head1 = head1->next;                
            }
            else{
                temp->next = head2;
                head2 = head2->next;
            }
            temp = temp->next;
        }
        
        while(head1){
            temp->next = head1;
            head1 = head1->next; 
            temp = temp->next;            
        }
        
        while(head2){
            temp->next = head2;
            head2 = head2->next; 
            temp = temp->next;
        }
        
        return merged->next;
    }
};