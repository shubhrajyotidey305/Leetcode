class Solution {
public:
    int dp[101][10001];
    int superEggDrop(int k, int n) {
        memset(dp, -1, sizeof(dp));
        return solve(k, n);
    }
    
    int solve(int e, int f) {
        if(e == 1) return f;
        if(f == 0 or f == 1) return f;

        if(dp[e][f] != -1) return dp[e][f];

        int ans = INT_MAX;       
        
        int l = 1, r = f;
        while(l<=r) {
            int mid = (l+r)/2;
            int a = solve(e-1, mid-1);
            int b = solve(e, f-mid);
            
            int temp = 1 + max(a, b);
            if(a < b) l = mid+1;
            else r = mid-1;
            ans = min(ans, temp);
        }
        return dp[e][f] = ans;
    }
};