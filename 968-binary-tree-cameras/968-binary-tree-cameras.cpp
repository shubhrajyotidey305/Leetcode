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
    int minCameraCover(TreeNode* root) {
        int ans = minCameraCover_helper(root);
        if(root->val == 1){
            ans++;
        }
        return ans;
    }
    
    int minCameraCover_helper(TreeNode* root){
        if(root->right == NULL && root->left == NULL){
            root->val = 1;
            return 0;
        }
        int ans = 0, l = 2, r = 2;
        if(root->left){
            ans += minCameraCover_helper(root->left);
            l = root->left->val;
        }
        if(root->right){
            ans += minCameraCover_helper(root->right);
            r = root->right->val;
        }
        if(l == 1 || r == 1){
            root->val = 3;
            return (ans+1);
        }
        if(l == 3 || r == 3){
            root->val = 2;
            return ans;
        }
        root->val = 1;
        return ans;
    }
};