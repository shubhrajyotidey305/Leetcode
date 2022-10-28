class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int prev, int n, vector<vector<int>> &costs) {
        if(i == n) {
            return 0;
        }    
        
        if(dp[i][prev] != -1) {
            return dp[i][prev];
        }
        
        int ans = INT_MAX;
        for(int j=0; j<3; j++) {
            if(j != prev)
                ans = min(ans, costs[i][j] + solve(i+1, j, n, costs));
        }
        return dp[i][prev] = ans;
    }
    
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        dp = vector<vector<int>> (n+1, vector<int>(5, -1));
        return solve(0, 4, n, costs);
    }
};