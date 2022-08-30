class Solution {
public:
    vector<int> dp;
    int deleteAndEarn(vector<int>& nums) {
        int n = 10001;
        vector<int> sum(n+2, 0);
        for(auto it:nums) {
            sum[it] += it;
        }
        dp.assign(n+2, -1);
        return solve(n, sum);
    }
    
    int solve(int n, vector<int> &sum) {
        if(n == 0) {
            return 0;
        }        
        
        if(dp[n] != -1) {
            return dp[n];
        }
        
        int op1 = 0, op2 = 0;        
        op1 = sum[n-1];
        if(n > 1) op1 += solve(n-2, sum);
        op2 = solve(n-1, sum);
        return dp[n] = max(op1, op2);
    }
};