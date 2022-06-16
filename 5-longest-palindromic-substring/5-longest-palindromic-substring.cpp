class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        pair<int,int> ans=make_pair(n,0);
        
        for(int diagonal=0; diagonal<n; diagonal++)
        {
            for(int i=0; i+diagonal<n; i++)
            {
                int j=i+diagonal;
                if(i==j) dp[i][j]=true;
                else if(i==j-1) dp[i][j]=(s[i]==s[j]);
                else dp[i][j]=(s[i]==s[j] && dp[i+1][j-1]);
                
                if(dp[i][j] && (j-i)>(ans.second-ans.first))
                {
                    ans.first=i;
                    ans.second=j;
                }
            }
        }
        
        return s.substr(ans.first,ans.second-ans.first+1);
    }
};