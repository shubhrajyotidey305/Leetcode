class Solution {
public:    
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();     
        
        if(a[n-1][m-1] == 1) return 0;
        
        vector<int> dp (m);
        dp[0] = 1;

        for(int i=0; i<n; i++) {
            vector<int> t(m);
            if(i == 0) {
                t[0] = 1;
            }        
            for(int j=0; j<m; j++) {
                if(i == 0 and j == 0) continue;            
                int op1 = 0,  op2 = 0;
                if(i > 0 and a[i-1][j] != 1) op1 = dp[j];
                if(j > 0 and a[i][j-1] != 1) op2 = t[j-1];
                t[j] = (op1 + op2);            
            }
            dp = t;
        }    
        return dp[m-1];
    }
};