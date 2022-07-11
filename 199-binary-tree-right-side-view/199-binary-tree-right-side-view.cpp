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
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return {};
        
        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;
        int x; 
        while(!q.empty()) {
            int n = q.size();               
            while(n--) {
                auto it = q.front();
                q.pop();
                x = it->val;
                if(it->left) {
                    q.push(it->left);
                }                
                if(it->right){
                    q.push(it->right);
                }
            }
            ans.push_back(x);
        }
        return ans;
    }
};