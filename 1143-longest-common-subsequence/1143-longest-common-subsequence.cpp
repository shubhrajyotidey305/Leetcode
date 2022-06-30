class Solution {
public:
    vector<vector<int>> dp;
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        dp = vector<vector<int>> (n+1, vector<int>(m+1, -1));
        return solve(s1, s2, n, m);
    }
    
    int solve(string &s1, string &s2, int n, int m){
        if(n==0 or m==0) return 0;
        
        if(dp[n][m] != -1) return dp[n][m];
        
        if (s1[n-1] == s2[m-1]) return dp[n][m] = 1 + solve(s1, s2, n-1, m-1); 
        else return dp[n][m] =  max(solve(s1, s2, n-1, m),solve(s1, s2, n, m-1));       
        
    }
};