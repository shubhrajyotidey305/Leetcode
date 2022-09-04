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
    map<int, map<int, multiset<int>>> mp;
    
    void solve(TreeNode *root, int col, int row) {
        if(root == NULL) {
            return;
        }    
        
        mp[col][row].insert(root->val);
        if(root->left) {
            solve(root->left, col-1, row+1);
        }
        if(root->right) {
            solve(root->right, col+1, row+1);
        }
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        solve(root, 0, 0);
        for(auto i:mp) {
            vector<int> res;
            for(auto j:i.second) {
                for(auto k:j.second) {
                    res.push_back(k);
                }
            }
            ans.push_back(res);
        }       
        
        return ans;
    }
};