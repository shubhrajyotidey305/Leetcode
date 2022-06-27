class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        for(auto &it:nums) total += it;
        target = abs(target);
        if (target > total || ((target + total)&1))
            return 0;
        int sum1 = (total + target) / 2;       
        
        return countSubset(nums, sum1);
    }
    
    int countSubset(vector<int> &arr, int sum) {
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
        dp[0][0] = 1;
        for(int i=1; i<=n; i++){
            if(arr[i-1] == 0) dp[i][0] = 2*dp[i-1][0];
            else dp[i][0] = dp[i-1][0];
        }
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=sum; j++){
                if(arr[i-1]<=j){
                    dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
};