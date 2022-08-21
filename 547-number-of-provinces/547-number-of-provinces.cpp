class Solution {
public:
    void dfs(int s, vector<int> adj[], vector<bool> &vis) {
        vis[s] = true;
        
        for(auto u:adj[s]) {
            if(!vis[u]) {
                dfs(u, adj, vis);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n];
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i != j) {
                    if(isConnected[i][j]) {
                        adj[i].push_back(j);
                    }
                }
            }
        }
        
        vector<bool> vis(n, false);
        int count  = 0;
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                dfs(i, adj, vis);
                count++;
            }
        }
        
        
        return count;
    }
};