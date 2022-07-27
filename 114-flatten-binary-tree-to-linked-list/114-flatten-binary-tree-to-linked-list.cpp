/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#define Node TreeNode
class Solution {
public:
    TreeNode *head, *prev = NULL;
    
    TreeNode * solve(TreeNode *root){
        if(root == NULL)
            return NULL;
        
        Node *l = root->left;
        Node *r = root->right;
        
        if(prev == NULL)
            head = root;
        else{
            prev->right = root;
            root->left = NULL;            
        }
        prev = root;
        solve(l);
        solve(r);
        return head;
    }
    
    void flatten(TreeNode* root) {
        if(root == NULL)
            return; 
        
        root = solve(root);
        root->left = NULL;                
    }
};