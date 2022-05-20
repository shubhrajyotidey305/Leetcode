class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        int m = a.size();
        int n = a[0].size();
        
        long long dp[m][n];
        memset(dp, 0, sizeof(dp));
        
        if(a[m-1][n-1] == 0)
            dp[m-1][n-1] = 1;
        
        for(int i = n-2; i>=0; i--){
            if(a[m-1][i] == 0){
                dp[m-1][i] += dp[m-1][i+1];    
            }
            
        }
        
        for(int i = m-2; i>=0; i--){
            if(a[i][n-1] == 0){
                dp[i][n-1] += dp[i+1][n-1];    
            }            
        }
        
        for(int i=m-2; i>=0; i--){
            for(int j=n-2; j>=0; j--){
                if(a[i][j] == 0){
                    dp[i][j] += dp[i+1][j] + dp[i][j+1];
                }
            }
        }
        return dp[0][0];
    }
};