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
    vector<int> v1, v2;
    
    void solve1(TreeNode* root) {
        if(root == NULL) {
            v1.push_back(INT_MAX);
            return;
        }
        
        v1.push_back(root->val);
        solve1(root->left);
        solve1(root->right);
    }
    void solve2(TreeNode* root) {
        if(root == NULL) {
            v2.push_back(INT_MAX);
            return;
        }
        
        v2.push_back(root->val);
        solve2(root->right);
        solve2(root->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) {
	        return true;
	    }
	    
	    solve1(root->left);
	    solve2(root->right);
	    
	    int n = v1.size(), m = v2.size();
	    if(n != m) {
	        return false;
	    } else {
	        for(int i=0, j=0; i<n and j<m; i++, j++) {
	            if(v1[i] != v2[j]) {
	                return false;
	            }
	        }
	        return true;
	    }        
    }
};