class Solution {
public:
    unordered_set<int> cycle;
    int cycle_str = -1;
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> adj[n+1];
        
        for(int i=0; i<n; i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<bool> vis(n+1, false);   
        dfs(1, adj, vis, -1);
        
        for(int i=n-1; i>=0; i--) {
            if(cycle.count(edges[i][0]) and cycle.count(edges[i][1])) {
                return edges[i];
            }
        }
        return {};        
    }
    
    void dfs(int u, vector<int> adj[], vector<bool> &vis, int par) {
        if(vis[u]) {
            cycle_str = u;
            return;
        }
        
        vis[u] = true;
        for(auto v:adj[u]) {
            if(v == par) {
                continue;                
            }
            
            if(cycle.empty()) {
                dfs(v, adj, vis, u);
            }
            
            if(cycle_str != -1) {
                cycle.insert(u);
            }
            
            if(u == cycle_str) {
                cycle_str = -1;
                return;
            }
        }
    }
};