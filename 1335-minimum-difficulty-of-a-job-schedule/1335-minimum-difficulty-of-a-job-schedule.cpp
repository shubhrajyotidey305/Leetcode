class Solution {
public:
//     int solve(int i, int d, vector<int> &arr, int& n, vector<vector<int>>& dp) {
//         if(d == 1) return *max_element(arr.begin()+i, arr.end());
//         if(dp[i][d] != -1) return dp[i][d];
//         int maxi = INT_MIN;
//         int res = INT_MAX;
//         for(int k = i; k<=n-d; k++){
//             maxi = max(maxi, arr[i]);
//             res = min(res, maxi + solve(k+1, d-1, arr, n, dp));
//         }
        
//         return dp[i][d] = res;
        
//     }
    
    int t[301][11];
    int solve(vector<int>& mat, int n, int idx, int d) {
        if(d == 1)
            return *max_element(begin(mat)+idx, end(mat));
        
        if(t[idx][d] != -1)
            return t[idx][d];
    
        
        int Max = INT_MIN;
        int result = INT_MAX;
        
        for(int i = idx; i<=n-d; i++) {
            Max = max(Max, mat[i]);
            result = min(result, Max + solve(mat, n, i+1, d-1));
        }
        return t[idx][d] = result;
    }
    
    int minDifficulty(vector<int>& arr, int d) {
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(d+1, -1));
        if(d > n) {
            return -1;
        }
         memset(t, -1, sizeof(t));
        // return solve(0, d, arr, n, dp);
         return solve(arr, n, 0, d);
    }
};