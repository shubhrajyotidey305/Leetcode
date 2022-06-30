class Solution {
public:
    int dp[1002][1002];
    int longestCommonSubsequence(string s1, string s2) {
        memset(dp, -1, sizeof(dp));
        return solve(s1, s2, s1.length(), s2.length());
    }
    
    int solve(string &s1, string &s2, int n, int m){
        if(n==0 or m==0) return 0;
        
        if(dp[n][m] != -1) return dp[n][m];
        
        if (s1[n-1] == s2[m-1]) return dp[n][m] = 1 + solve(s1, s2, n-1, m-1); 
        else return dp[n][m] =  max(solve(s1, s2, n-1, m),solve(s1, s2, n, m-1));       
        
    }
};