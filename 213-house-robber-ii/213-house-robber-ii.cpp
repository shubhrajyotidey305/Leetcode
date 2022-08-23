class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1) {
            return nums[0];
        }
        
        vector<int> a, b;
        vector<int> dp(n, -1);
        
        for(int i=0; i<n-1; i++) a.push_back(nums[i]);
        for(int i=1; i<n; i++) b.push_back(nums[i]);
        
        int ans1 = solve(a, a.size(), dp);
        dp.assign(n, -1);
        int ans2 = solve(b, b.size(), dp);
        
        return max(ans1, ans2);
    }
    
    int solve(vector<int> &nums, int n, vector<int> &dp) {
        if(n <= 0) {
            return 0;
        }
        
        if(dp[n] != -1) {
            return dp[n];
        }
        
        int op1 = nums[n-1] + solve(nums, n-2, dp);
        int op2 = solve(nums, n-1, dp);
        return dp[n] = max(op1, op2);
    }
};