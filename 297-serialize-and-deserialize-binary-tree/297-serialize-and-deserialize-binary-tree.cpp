/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<bits/stdc++.h>
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) {
            return "#";
        }
        string s;
        queue<TreeNode*> q;
        q.push(root);
        s += to_string(root->val) + ",";
        
        while(!q.empty()) {
            auto u = q.front();
            q.pop();            
            
            if(u->left) {
                q.push(u->left);
                s += to_string(u->left->val) + ",";
            } else {
                s += "#,";
            }
            
            if(u->right) {
                q.push(u->right);
                s += to_string(u->right->val) + ",";
            } else {
                s += "#,";
            }
        } 
        s.pop_back();
        // cout << s << endl;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        int i = 0, n = s.size();
        if(s[i] == '#') {
            return NULL;
        }
        vector<string> v;        
        while(i<n) {
            string t;
            while(i<n and s[i] != ',') {                
                t += s[i];
                i++;
            }
            if(!t.empty()) v.push_back(t);            
            i++;
        }
        
        // for(auto it:v) {
        //     cout << it << " - ";
        // }
        
        queue<TreeNode*> q;
        i = 0, n = v.size();
        TreeNode *root = new TreeNode(stoi(v[i]));
        q.push(root);    
        ++i;
        
        while(!q.empty() and i<n) {
            auto u = q.front();
            q.pop();
            
            if(v[i] != "#") {
                TreeNode *node = new TreeNode(stoi(v[i]));
                u->left = node;
                ++i;
                q.push(node);
            } else {
                u->left = NULL;
                ++i;
            }
            
            if(v[i] != "#") {
                TreeNode *node = new TreeNode(stoi(v[i]));
                u->right = node;
                ++i;
                q.push(node);
            } else {
                u->right = NULL;
                ++i;
            }           
            
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));