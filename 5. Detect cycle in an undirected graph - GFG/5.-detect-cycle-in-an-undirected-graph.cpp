// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int v, vector<int> adj[]) {
        // Code here
        vector<bool> vis(v, 0);
        for(int i=0; i<v; i++){
            if(!vis[i]){
                if(dfs(adj, vis, i, -1))
                    return true;
            }
        }
        return false;
    }
    
    bool dfs(vector<int> adj[], vector<bool> &vis, int s, int parent){
        vis[s] = true;
        
        for(auto u:adj[s]){
            if(!vis[u]){
                if(dfs(adj, vis, u, s))
                    return true;
            }
            else if(u!=parent)
                return true;
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends