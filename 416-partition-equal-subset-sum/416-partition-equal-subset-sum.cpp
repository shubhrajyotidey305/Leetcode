class Solution {
public:
    vector<vector<int>> dp;
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(int i=0; i<n; i++) total += nums[i];
        dp = vector<vector<int>> (n+1, vector<int>(total+1, -1));
        
        if(total & 1) return false;        
        total /= 2;
        return solve(n, total, nums);       
        
    }
    
    bool solve(int n, int sum, vector<int> &nums){
        if(n == 0 or sum == 0){
            return sum == 0 ? true : false;
        }
        
        if(dp[n][sum]!=-1) return dp[n][sum];
        if(nums[n-1]<=sum) return dp[n][sum] = solve(n-1, sum-nums[n-1], nums) or solve(n-1, sum, nums);
        else return dp[n][sum] = solve(n-1, sum, nums);
    }
};