//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int u, int par, int vis[], vector<int> adj[]) {
        vis[u] = true;
        
        for(auto v:adj[u]) {
            if(!vis[v]) {
                if(dfs(v, u, vis, adj)) 
                    return true;
            } else if(v != par) {
                return true;
            }
        }
        return false;
    }
    bool isCycle(int v, vector<int> adj[]) {
        // Code here
        int vis[v] = {0};
        for(int i=0; i<v; i++) {
            if(!vis[i]) {
                if(dfs(i, -1, vis, adj)) {
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
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
}
// } Driver Code Ends