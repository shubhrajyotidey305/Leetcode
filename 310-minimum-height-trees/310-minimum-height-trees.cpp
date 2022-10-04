class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) {
            return {0};
        }
        
        vector<int> adj[n];
        vector<int> in_degree(n, 0);
        for(int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            
            in_degree[edges[i][0]]++;
            in_degree[edges[i][1]]++;
        }
        
        vector<int> ans;
        queue<int> q;
        
        for(int i=0; i<n; i++) {
            if(in_degree[i] == 1) {
                q.push(i);
            }
        }
        
        while(!q.empty()) {
            ans.clear();
            int sz = q.size();
            
            while(sz--) {
                auto u = q.front();
                q.pop();
                
                ans.push_back(u);
                for(auto v:adj[u]) {
                    if(--in_degree[v] == 1) 
                        q.push(v);
                }                
            }
        }
        return ans;
    }
};