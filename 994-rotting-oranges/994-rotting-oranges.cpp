class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int min = 0, tot = 0, cnt = 0;
        
        queue<pair<int, int>> q;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]!=0) tot++;
                if(grid[i][j]==2) q.push({i, j});
            }
        }
        
        int dx[] = {0, 0, -1, 1};
        int dy[] = {1, -1, 0, 0};
        
        while(!q.empty()){
            int k = q.size();
            cnt += k;
            
            while(k--){
                int x = q.front().first, y = q.front().second;
                q.pop();
                for(int i=0; i<4; i++){
                    int nx = x+dx[i], ny = y+dy[i];
                    if(nx<0 or ny<0 or nx>=m or ny>=n or grid[nx][ny]!=1) continue;
                    grid[nx][ny] = 2;
                    q.push({nx, ny});
                }   
            }
            if(!q.empty()) min++;      
        }
        
        return (tot == cnt)?min:-1;
        
    }
};