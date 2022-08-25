class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> dp(m);    
        dp[0] = grid[0][0];

        for(int i=0; i<n; i++) {
            vector<int> t(m);
            if(i == 0) t[0] = grid[0][0];        
            for(int j=0; j<m; j++) {
                if(i == 0 and j == 0) continue;
                int op1 = 1e9, op2 = 1e9;            
                if(i > 0) op1 = dp[j];
                if(j > 0) op2 = t[j-1];            
                t[j] = grid[i][j] + min(op1, op2);            
            }
            dp = t;
        }
        return dp[m-1];
    }
};