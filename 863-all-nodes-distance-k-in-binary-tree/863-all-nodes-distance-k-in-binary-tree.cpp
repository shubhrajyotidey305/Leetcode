/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent; 
    void getParent(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            auto u = q.front();
            q.pop(); 
            
            if(u->left) {
                parent[u->left] = u;
                q.push(u->left);
            }
            
            if(u->right) {
                parent[u->right] = u;
                q.push(u->right);
            }
        }
    }    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(root == NULL) {
            return {};
        }
        getParent(root);
        unordered_map<TreeNode*, bool> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target] = true;
        int level = 0;
        
        while(!q.empty()) {
            int n = q.size();
            if(level++ == k) {
                break;
            }
            
            while(n--) {
                auto u = q.front();
                q.pop();
                
                if(u->left and !vis[u->left]) {
                    q.push(u->left);
                    vis[u->left] = true;
                }
                if(u->right and !vis[u->right]) {
                    q.push(u->right);
                    vis[u->right] = true;
                }
                if(parent[u] and !vis[parent[u]]) {
                    q.push(parent[u]);
                    vis[parent[u]] = true;
                }
            }
        }
        
        vector<int> ans;
        while(!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }
        
        return ans;
    }
};