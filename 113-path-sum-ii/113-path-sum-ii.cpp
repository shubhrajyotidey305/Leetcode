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
    vector<vector<int>> ans;

    void solve(vector<int> &v, TreeNode *curr, int currsum, int target){
        if(!curr)
            return;
        
        currsum += curr->val;
        v.push_back(curr->val); 
        
        
        if(!curr->left && !curr->right && currsum == target) {
            ans.push_back(v);
        }
        
        solve(v, curr->left,  currsum, target); 
        solve(v, curr->right, currsum, target); 
        
        v.pop_back(); 
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> v;
        ans.clear();
        
        solve(v, root, 0, targetSum);
        return ans;
    }
};