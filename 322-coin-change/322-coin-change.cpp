class Solution {
public:
    int coinChange(vector<int>& coins, int sum) {
        int n = coins.size();
        
        long long dp[sum+1];        
        for(int i=0; i<=sum; i++)
            dp[i] = INT_MAX;
        
        dp[0] = 0;
        
        
        for(int i=0; i<n; i++){
            for(int j=coins[i]; j<=sum; j++){
                dp[j] = min(dp[j], 1+dp[j-coins[i]]); 
            }
        }
        return dp[sum] == INT_MAX?-1:dp[sum];
    }
};