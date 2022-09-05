/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<Node*> q;
        
        q.push(root);
        q.push(NULL);
        vector<int> v;
        while(!q.empty())
        {
            Node* curr=q.front();
            
            q.pop();
            
            if(curr!=NULL)
            {
                v.push_back(curr->val);
                
                for(auto x : curr->children)
                {
                    if(x!=NULL) q.push(x);
                }
                
                
                
                
            }
            else
            {
                if(!q.empty())
                {
                    q.push(NULL);
                    ans.push_back(v);
                    v.clear();
                }
            }
            
            
            
            
        }
        
        ans.push_back(v);
        
        return ans;
        
        
    }
};