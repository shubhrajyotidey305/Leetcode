class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n-1, m-1, grid, dp);
    }
    
    int solve(int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp) {
        if(n == 0 and m == 0) {
            return grid[0][0];
        }

        if(dp[n][m] != -1) {
            return dp[n][m];
        }

        int op1 = 1e9, op2 = 1e9;
        if(n-1 >= 0) op1 = solve(n-1, m, grid, dp);
        if(m-1 >= 0) op2 = solve(n, m-1, grid, dp);    
        return dp[n][m] = grid[n][m] + min(op1, op2);
    }
};