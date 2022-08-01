class Solution {
public:
    int dp[102][102];
    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, m, n);
    }
    
    int solve(int i, int j, int m, int n) {
        if(i == m-1 and j == n-1) {
            return 1;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int l = -1, r = -1;
        if(isSafe(i+1, j, m, n)) {
            l = solve(i+1, j, m, n);
        }
        
        if(isSafe(i, j+1, m, n)) {
            r = solve(i, j+1, m, n);
        }
        
        if(l == -1 and r != -1) return dp[i][j] = r;
        if(l != -1 and r == -1) return dp[i][j] = l;
        if(l != -1 and r!= -1) return dp[i][j] = l+r;
        return dp[i][j] = 0;     
        
    }
    
    bool isSafe(int i, int j, int m, int n) {
        return (i >= 0 and i < m and j >=0 and j < n);
    }
};