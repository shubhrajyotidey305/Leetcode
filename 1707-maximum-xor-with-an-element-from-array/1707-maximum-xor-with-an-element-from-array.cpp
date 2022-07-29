struct Node {
    Node *links[2];
    
    bool containskey(int bit) {
        return links[bit] != NULL;
    }
    
    Node *get(int bit) {
        return links[bit];
    }
    
    void put(int bit, Node *temp) {
        links[bit] = temp;
    }
};

class Trie {
    public:
    Node *root;
    
    Trie() {
        root = new Node();
    }
    
    void insert(int num) {
        Node *node = root;
        for(int i=31; i>=0; i--) {
            int bit = (num >> i) & 1;            
            if(!node->containskey(bit)) {
                node->put(bit, new Node());
            }            
            node = node->get(bit);
        }
    }
    
    int getmax(int num) {
        Node *node = root;
        int ans = 0;
        
        for(int i=31; i>=0; i--) {
            int bit = (num >> i) & 1;
            
            if(node->containskey(1-bit)) {
                ans = ans | (1<<i);
                node = node->get(1-bit);
            } else {
                node = node->get(bit);
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans(queries.size(), 0); 
        vector<pair<int, pair<int,int>>> offlineQueries; 
        sort(arr.begin(), arr.end()); 
        int index = 0;
        for(auto &it: queries) {
            offlineQueries.push_back({it[1],{it[0], index++}}); 
        }
        sort(offlineQueries.begin(), offlineQueries.end()); 
        int i = 0; 
        int n = arr.size(); 
        Trie trie; 

        for(auto &it : offlineQueries) {
            while(i < n && arr[i] <= it.first) {
                trie.insert(arr[i]); 
                i++; 
            }
            if(i!=0) ans[it.second.second] = trie.getmax(it.second.first); 
            else ans[it.second.second] = -1; 
        }
        return ans;         
    }
};