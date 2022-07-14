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
#define Node TreeNode
class Solution {
public:
    int preidx = 0;
    
    Node* solve(vector<int>& pre, vector<int>& in, int is, int ie){
        if(is>ie)
            return NULL;
        
        Node *root = new Node(pre[preidx++]);
        int inidx;
        for(int i=is; i<=ie; i++){
            if(in[i] == root->val){
                inidx = i;
                break;
            }
        }
        root->left = solve(pre, in, is, inidx-1);
        root->right = solve(pre, in, inidx+1, ie);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        Node *root = solve(preorder, inorder, 0, n-1);
        return root;
    }
};