class Solution {
public:
    int dp[501][501];
    int recur(string &s,string &t,int n,int m){
        if(n==0||m==0)return dp[n][m] = 0;
        if(dp[n][m]!=-1)return dp[n][m];
        if(s[n-1]==t[m-1]){
            return dp[n][m] = 1+recur(s,t,n-1,m-1);
        }
        else{
            return dp[n][m] = max(recur(s,t,n-1,m),recur(s,t,n,m-1));
        }
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        memset(dp,-1,sizeof(dp));
        return n+m-2*recur(word1,word2,word1.size(),word2.size());
    }
};