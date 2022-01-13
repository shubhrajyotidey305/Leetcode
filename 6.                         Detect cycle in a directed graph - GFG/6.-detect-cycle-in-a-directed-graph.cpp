// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        bool vis[V] = {0};
        bool recur_st[V] = {0};
        
        for(int i=0; i<V; i++){
            if(!vis[i] and dfs(adj, vis, recur_st, i)){
                return true;
            }
        }
        return false;
        
    }
    
    bool dfs(vector<int> adj[], bool vis[], bool recur_st[], int s){
        vis[s] = true;
        recur_st[s] = true;
        
        for(auto u:adj[s]){
            if(!vis[u] and dfs(adj, vis, recur_st, u)){
                return true;
            }
            else if(recur_st[u]){
                return true;
            }
        }
        recur_st[s] = false;
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends