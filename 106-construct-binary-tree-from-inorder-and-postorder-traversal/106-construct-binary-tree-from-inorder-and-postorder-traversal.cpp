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
    #define Node TreeNode
    unordered_map<int, int> mp;
    Node *solve(int in_str, int in_end, vector<int>& in, int post_str, int post_end, vector<int>& post) {
        if(in_str > in_end or post_str > post_end) {
            return NULL;
        }

        Node *root = new Node(post[post_end]);
        int in_root = mp[post[post_end]];
        int num_right = in_end - in_root;

        root->right = solve(in_root+1, in_end, in, post_end-num_right, post_end-1, post);
        root->left = solve(in_str, in_root-1, in, post_str, post_end-num_right-1, post);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        mp.clear();
        int n = post.size();
        for(int i=0; i<n; i++) {
            mp[in[i]] = i;
        }
        return solve(0, n-1, in, 0, n-1, post);        
    }
};