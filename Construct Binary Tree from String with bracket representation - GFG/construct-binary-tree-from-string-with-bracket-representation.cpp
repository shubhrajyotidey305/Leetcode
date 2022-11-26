//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/* This function is to print the inorder of the tree  */
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}



// } Driver Code Ends
//User function Template for C++

/*
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
*/


class Solution{
public:
    // function to construct tree from string
    Node *treeFromString(string str){
        // code here
        stack<Node*> st;
        int i = 0;
        int n = str.length();
        while(i < n){
            if(str[i] == '('){
                i++;
            }
            else if(str[i] == ')'){
                st.pop();
                i++;
            }
            else{
                int val = 0;
                int j = i;
                while(j < n && (str[j] - '0' >= 0 && str[j] - '0' <= 9)){
                    val = val*10 + (str[j] - '0');
                    j++;
                }
                Node* next = new Node(val);
                if(st.empty() == false){
                    if(st.top()->left == NULL){
                        st.top()->left = next;
                    }
                    else{
                        st.top()->right = next;
                    }
                }
                st.push(next);
                i = j;
            }
        }
        return st.top();
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node *root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends