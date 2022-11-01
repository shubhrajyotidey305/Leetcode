class Solution {
public:
    int solve(int j, vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        for(int i=0; i<m; i++) {
            int k = j + grid[i][j];
            if(k < 0 or k >= n or grid[i][j] != grid[i][k]) {
                return -1;
            }
            j = k;
        }
        return j;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();   
        
        vector<int> pos;
        for (int j = 0; j < n; ++j) pos.push_back(solve(j, grid));
        return pos;        
    }
};