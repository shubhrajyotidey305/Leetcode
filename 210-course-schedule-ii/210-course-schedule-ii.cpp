class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> adj[n];
        vector<int> indegree(n, 0);
        vector<int> ans;
        
        for(int i=0; i<pre.size(); i++) {
            adj[pre[i][1]].push_back(pre[i][0]);
            indegree[pre[i][0]]++;
        }
        
        queue<int> q;
        for(int i=0; i<n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        int count = 0;
        while(!q.empty()) {
            auto u = q.front();
            q.pop();
            
            ans.push_back(u);
            for(auto v:adj[u]) {
                if(--indegree[v] == 0) {
                    q.push(v);
                }
            }
            count++;
        }
        
        if(count == n) {
            return ans;
        } else {
            return {};
        }
     }
};