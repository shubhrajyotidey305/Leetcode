class Solution {
public:
    bool check(int r, int c, int n, int m) {
        return (r > -1 and r < n and c > -1 and c < m);
    }
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, -1));
        queue<vector<int>> q;
        q.push({0, 0, 0, k});
        vis[0][0] = true;
        
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        
        while(!q.empty()) {
            auto u = q.front();
            q.pop();
            
            int x = u[0], y = u[1], dist = u[2], obs = u[3];
            
            if(x == n-1 and y == m-1) {
                return dist;
            }
            
            if(grid[x][y]) {
                if(!obs) continue;
                else obs--;
            }
            
            for(int i=0; i<4; i++) {
                int r = x + dx[i];
                int c = y + dy[i];
                
                if(check(r, c, n, m) and vis[r][c] < obs) {
                    vis[r][c] = obs;
                    q.push({r, c, 1 + dist, obs});                    
                }                
            }
        }
        return -1;
    }
};