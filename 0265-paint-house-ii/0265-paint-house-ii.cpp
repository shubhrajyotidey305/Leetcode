class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int prev, int n, int k, vector<vector<int>> &costs) {
        if(i == n) {
            return 0;
        }    
        
        if(dp[i][prev] != -1) {
            return dp[i][prev];
        }
        
        int ans = INT_MAX;
        for(int j=0; j<k; j++) {
            if(j != prev)
                ans = min(ans, costs[i][j] + solve(i+1, j, n, k, costs));
        }
        return dp[i][prev] = ans;
    }
    
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        int k = costs[0].size();
        dp = vector<vector<int>> (n+1, vector<int>(k+2, -1));
        return solve(0, k+1, n, k, costs);
    }
};