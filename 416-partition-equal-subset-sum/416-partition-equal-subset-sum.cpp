class Solution {
public:
    vector<vector<int>> dp;
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(int i=0; i<n; i++) total += nums[i];
        dp = vector<vector<int>> (n+1, vector<int>(total+1, -1));
        return solve(n, 0, total, nums);
    }
    
    bool solve(int n, int sum, int total, vector<int> &nums){
        if(n == 0){
            return sum == total - sum;
        }   
        
        if(sum == total - sum){
            return true;
        }
        
        if(dp[n][sum]!=-1) return dp[n][sum];    
        return dp[n][sum] = (solve(n-1, sum+nums[n-1], total, nums) || solve(n-1, sum, total, nums));
    }
};