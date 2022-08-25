class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m));    
        dp[0][0] = grid[0][0];

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(i == 0 and j == 0) continue;
                int op1 = 1e9, op2 = 1e9;            
                if(i > 0) op1 = dp[i-1][j];
                if(j > 0) op2 = dp[i][j-1];            
                dp[i][j] = grid[i][j] + min(op1, op2);
            }
        }
        return dp[n-1][m-1];
    }
};