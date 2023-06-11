//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool bfs(int u, vector<bool>& vis, vector<int> adj[]) {
        queue<pair<int, int>> q;
        q.push({u, -1});
        vis[u] = true;
        
        while(!q.empty()) {
            int node = q.front().first;
            int par = q.front().second;
            q.pop();
            
            for(auto v:adj[node]) {
                if(!vis[v]) {
                    vis[v] = true;
                    q.push({v, node});
                } else if(par != v) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool isCycle(int v, vector<int> adj[]) {
        // Code here
        
        vector<bool> vis(v, false);
        
        for(int i=0; i<v; i++) {
            if(!vis[i])
                if(bfs(i, vis, adj)) {
                    return true;
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