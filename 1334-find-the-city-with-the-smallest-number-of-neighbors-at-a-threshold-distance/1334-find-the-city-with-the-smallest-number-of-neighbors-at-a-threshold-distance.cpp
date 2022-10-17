class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int d) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        
        for(auto it:edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];            
            dist[u][v] = w;
            dist[v][u] = w;
        }
        
        for(int i=0; i<n; i++) {
            dist[i][i] = 0;
        }
        
        for(int k=0; k<n; k++) {
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    if(dist[i][k] == INT_MAX or dist[k][j] == INT_MAX) {
                        continue;
                    } else {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        
        int distance = INT_MAX, ans = 0;
        for(int i=0; i<n; i++) {
            int count = 0;
            for(int j=0; j<n; j++) {
                if(i!=j) {
                    if(dist[i][j] <= d) {
                        count++;
                    }
                }
            }
            // cout << count << endl;
            if(count <= distance) {
                distance = count;
                ans = i;
            }
        }
        return ans;
    }
};