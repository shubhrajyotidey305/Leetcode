class Solution {
public:
    int m,n;
    
    bool isSafe(vector<vector<char>> &grid, int row, int col, vector<vector<bool>> &visited){
        return ((row >=0 && row < m) && (col >= 0 && col < n) && (grid[row][col] == '1' && !visited[row][col]));
    }
    
    void DFS(vector<vector<char>> &grid, int row, int col, vector<vector<bool>> &visited){
        static int rownum[] = { -1, 0, 0, 1};
        static int colnum[] = { 0, -1, 1, 0};   
        
        visited[row][col] = true;
        
        for(int i=0; i<4; i++){
            if(isSafe(grid, row + rownum[i], col + colnum[i], visited)){
                DFS(grid, row + rownum[i], col + colnum[i], visited);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n, 0));
        
        int cnt = 0;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    DFS(grid, i, j, visited);
                    cnt++;
                }
            }
        }
        return cnt;    
    }
};