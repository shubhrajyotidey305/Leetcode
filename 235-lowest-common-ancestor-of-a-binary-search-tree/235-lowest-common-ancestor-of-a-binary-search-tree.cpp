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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val <= root->val && q->val >= root->val)
            return root;
        if(p->val >= root->val && q->val <= root->val)
            return root;
        if(p->val == q->val)
            return p;
        
        vector<TreeNode*> a;
        vector<TreeNode*> b;
        
        TreeNode* f = root;
        TreeNode* s = root;
        
        while(f->val != p->val){
            a.push_back(f);
            if(f->val > p->val){
                f = f->left;
            }
            else{
                f = f->right;
            }
        }
        a.push_back(f);
        
        while(s->val != q->val){
            b.push_back(s);
            if(s->val > q->val){
                s = s->left;
            }
            else{
                s = s->right;
            }
        }
        b.push_back(s);
        
        int i = 0;
        while(i < a.size() && i < b.size()){
            if(a[i] != b[i])
                return a[i-1];
            i++;
        }
        
        if(i == a.size()){
            return a[i-1];
        }
        return b[i-1];
        
    }
};