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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) {
        return {};
    }
    vector<vector<int>> ans;
    queue<TreeNode*> q;
    q.push(root);
    bool fl = false;
    
    while(!q.empty()) {
        int n = q.size();
        
        fl = !fl;
        vector<int> res;
        while(n--) {
            auto u = q.front();
            q.pop();
            res.push_back(u->val);
            if(u->left) {
                q.push(u->left);
            }
            if(u->right) {
                q.push(u->right);
            }            
        }
        if(fl) {
            ans.push_back(res);           
        } else{
            reverse(res.begin(), res.end());
            ans.push_back(res);
        }        
    }
    return ans;        
    }
};