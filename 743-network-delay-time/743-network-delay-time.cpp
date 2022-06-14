class Solution {
    typedef pair<int, int> pii;
public:
    int networkDelayTime(vector<vector<int>>& edges, int n, int k) {
        vector<int> v(n+1);
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        int ans = -1;
        for(int i=1; i<=n; i++) v[i] = INT_MAX;

        pq.push({0,k});

        while(!pq.empty()) {
            auto u = pq.top();
            pq.pop();

            while(!pq.empty() and v[u.second] != INT_MAX) {
                u = pq.top();
                pq.pop();
            }

            if(v[u.second] != INT_MAX) break;

            v[u.second] = u.first;
            for(auto &it:edges) {
                if(it[0] == u.second and v[it[1]] == INT_MAX) {
                    pq.push({it[2] + u.first, it[1]});
                }
            }
        }

        for(int i=1; i<=n; i++) {
            ans = max(ans, v[i]);
            cout << v[i] << " ";
        }

        return (ans == INT_MAX)? -1 : ans;
    }
    
};