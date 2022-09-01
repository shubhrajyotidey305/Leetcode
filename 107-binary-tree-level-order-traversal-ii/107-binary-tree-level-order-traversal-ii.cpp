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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) {
            return ans;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int sz = q.size();
            vector<int> res;
            while(sz--) {
                auto u = q.front();
                q.pop();
                
                if(u->left) {
                    q.push(u->left);
                }
                
                if(u->right) {
                    q.push(u->right);
                }
                res.push_back(u->val);                
            }
            ans.push_back(res);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};