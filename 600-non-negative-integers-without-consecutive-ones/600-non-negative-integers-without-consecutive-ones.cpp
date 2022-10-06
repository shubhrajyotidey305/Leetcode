class Solution {
public:
    int dp[32][2][2];
    int solve(string &num, int n, int prev, bool tight) {
        if(n == 0) {
            return 1;
        }        
        
        if(dp[n][prev][tight] != -1) {
            return dp[n][prev][tight];
        }
        
        int ans = 0;
        int ub = tight ? num[num.length()-n]-'0' : 1;
        
        for(int i=0; i<=ub; i++) {
            if(prev == 0) {
                ans += solve(num, n-1, i, tight & (i == ub));
            }
            if(prev == 1 and i == 0) {
                ans += solve(num, n-1, 0, tight & (i == ub));
            }            
        }
        return dp[n][prev][tight] = ans;
    }
    
    int findIntegers(int n) {
        string num;
        while(n) {
            num += (n%2) + '0';
            n /= 2;
        }
        reverse(num.begin(), num.end());
        memset(dp, -1, sizeof dp);
        return solve(num, num.length(), 0, 1);
    }
};