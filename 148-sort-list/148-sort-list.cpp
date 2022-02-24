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
    Node *merge(Node *head1, Node *head2){
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
    
    ListNode *middle(ListNode *head){
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(slow->next && fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode *mid = middle(head);
        ListNode *head2 = mid->next;
        mid->next = NULL;
        
        Node *finalhead = merge(sortList(head), sortList(head2));
        return finalhead;      
        
        
    }
};