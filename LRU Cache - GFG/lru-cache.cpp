//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

struct Node {
    int key;
    int val;
    Node *prev;
    Node *next;

    Node(int key, int val) {
        this->key = key;
        this->val = val;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache
{
    private:
    int cap = 0;
    unordered_map<int, Node*> mp;    
    Node *head;
    Node *tail;
    int count = 0;
    
    void deleteNode(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;        
    }

    void addToHead(Node *node) {
        node->next = head->next;
        node->next->prev = node;
        node->prev = head;
        head->next = node;
    }

    public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int capacity)
    {
        // code here
        cap = capacity;
        mp = unordered_map<int, Node*> ();
        count = 0;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        head->prev = NULL;
        tail->next = NULL;
    }
    
    //Function to return value corresponding to the key.
    int get(int key)
    {
        // your code here
        if(mp[key]) {
            Node *node = mp[key];
            int res = node->val;
            deleteNode(node);
            addToHead(node);
            return res;
        } else {
            return -1;
        }
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
        // your code here   
        if(mp[key]) {
            Node *node = mp[key];
            node->val = value;
            deleteNode(node);
            addToHead(node);
        } else {
            Node *node = new Node(key, value);
            mp[key] = node;
            if(count < cap) {
                count++;
                addToHead(node); 
            } else {
                mp.erase(tail->prev->key);
                deleteNode(tail->prev);
                addToHead(node);
            }
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends