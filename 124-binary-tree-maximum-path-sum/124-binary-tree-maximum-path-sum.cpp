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
    int res = -1e9;
    int solve(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }

        int l = max(0, solve(root->left));
        int r = max(0, solve(root->right));

        res = max(res, root->val + l + r);
        return root->val + max(l, r);
    }
    int maxPathSum(TreeNode* root) {
        res = -1e9;
        solve(root);
        return res;
    }
};