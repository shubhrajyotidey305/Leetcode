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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) {
            return false;
        }
        if(root->left == NULL and root->right == NULL) {
            if(targetSum - root->val == 0) {
                return true;
            }
        }
        
        bool op1 = false, op2 = false;         
        op1 = hasPathSum(root->left, targetSum - root->val);        
        op2 = hasPathSum(root->right, targetSum - root->val);
        
        return op1 or op2;
    }
};