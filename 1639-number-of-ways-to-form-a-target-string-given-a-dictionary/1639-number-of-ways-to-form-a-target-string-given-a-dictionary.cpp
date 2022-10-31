class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int n = target.size(), mod = 1e9 + 7;
        vector<long long> dp(n+1);
        dp[0] = 1;
        
        for(int i=0; i<words[0].size(); i++) {
            vector<int> f(26, 0);
            for(auto &s:words) {
                f[s[i]-'a']++;
            }
            
            
            for(int j=n-1; j>=0; j--) {
                dp[j+1] += (dp[j] * f[target[j]-'a']) % mod;
            }
        }
        return dp[n] % mod;
    }
};