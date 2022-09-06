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
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        solve(root);
        if(root->val == 0 and !root->left and !root->right) {
            return NULL;
        }
        return root;
    }
    
    bool solve(TreeNode* root) {
        if(root == NULL) {
            return false;
        }
        
        bool op1, op2, op3;
        op1 = (root->val == 1);        
        op2 = solve(root->left);
        op3 = solve(root->right);
        
        if(!op2) {
            root->left = NULL;
        }
        if(!op3) {
            root->right = NULL;
        }
        return op1 or op2 or op3;
        
    }
};