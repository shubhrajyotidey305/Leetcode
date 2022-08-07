class Solution {
public:
    int countVowelPermutation(int n) {
        vector<vector<long long>> dp(n+1,vector<long long>(6,0));
        int mod=1000000007;
        for(int i=1;i<=5;i++)dp[1][i]=1;
        for(int i=2;i<=n;i++){
            dp[i][1]=((dp[i-1][2]%mod)+(dp[i-1][3]%mod)+(dp[i-1][5]%mod))%mod;
            dp[i][2]=(dp[i-1][3]%mod+dp[i-1][1]%mod)%mod;
            dp[i][3]=(dp[i-1][2]%mod+dp[i-1][4]%mod)%mod;
            dp[i][4]=dp[i-1][3]%mod;
            dp[i][5]=(dp[i-1][3]%mod+dp[i-1][4]%mod)%mod;
        }
        int sum=0;
        for(int i=1;i<=5;i++)sum=(sum%mod)+(dp[n][i]%mod);
        return sum%mod;
    }
};