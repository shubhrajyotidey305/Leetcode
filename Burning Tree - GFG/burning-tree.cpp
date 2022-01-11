// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        unordered_map<Node *, Node *> mp;
        Node *res = bfsToFindParent(root, target, mp);  
        int t = calTime(root, res, mp);
        return t;
    }
    
    int calTime(Node *root, Node* start, unordered_map<Node*, Node*> &mp){
        unordered_map<Node *, bool> vis;
        int t = 0;
        vis[start] = true;
        
        queue<Node*> q;
        q.push(start);
        
        while(!q.empty()){
            int size = q.size();
            bool flag = false;
            
            while(size--){
                auto it = q.front();
                q.pop();
                
                if(it->left and !vis[it->left]){
                    flag = true;
                    vis[it->left] = true;
                    q.push(it->left);
                }
                
                if(it->right and !vis[it->right]){
                    flag = true;
                    vis[it->right] = true;
                    q.push(it->right);
                }
                
                if(mp[it] and !vis[mp[it]]){
                    flag = true;
                    vis[mp[it]] = true;
                    q.push(mp[it]);
                }
            }
            
            if(flag) t++;
        }
        
        return t;
    }
    
    Node *bfsToFindParent(Node *root, int target, unordered_map<Node*, Node*> &mp){
        queue<Node*> q;
        q.push(root);
        Node *res = NULL;
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            if(it->data == target) res = it; 
            if(it->left){
                mp[it->left] = it;
                q.push(it->left);
            }
            if(it->right){
                mp[it->right] = it;
                q.push(it->right);
            }
        }
        return res;
        
    }
    
    
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends