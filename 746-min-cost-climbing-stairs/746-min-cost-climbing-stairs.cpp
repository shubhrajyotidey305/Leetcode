class Solution {
public:
    vector<int> dp;
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        dp = vector<int>(n+1, -1);
        return min(solve(cost, n, 0), solve(cost, n, 1));
    }
    
    int solve(vector<int> &cost, int n, int idx) {
        if(idx >= n){
            return 0;
        }
        
        if(dp[idx] != -1) return dp[idx];
        
        return dp[idx] = min(cost[idx] + solve(cost, n, idx+1), cost[idx] + solve(cost, n, idx + 2));
    }
};