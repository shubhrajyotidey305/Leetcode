class Solution {
public:
    int cnt = 0;
    int dp[22][2006]; 
    // n => 22, target + 1000 => 2002
    int solve(vector<int>& nums, int target, int n) {
        if(n == 0){
            if(target == 0) return 1;
            return 0;
        }       
        
        // if(dp[n][target + 1001]!=-1){            
        //     return dp[n][target + 1001];
        // }
        
        
        return solve(nums, target-nums[n-1], n-1) + solve(nums, target+nums[n-1], n-1);                     
        
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(nums, target, n);
        // return dp[n][target + 1001];
    }
};