class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        int dp[n+1][n+1];
        memset(dp, 0, sizeof(dp));

        for(int i=n-1; i>=0; i--) {
            for(int j=i-1; j>=-1; j--) {
                if(j == -1 or arr[i] > arr[j]) {
                    dp[i][j+1] = max(1 + dp[i+1][i+1], dp[i+1][j+1]);
                } else {
                    dp[i][j+1] = dp[i+1][j+1];
                }            
            }
        }
        return dp[0][0];
    }
};