class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
         int len = strs.size() ;
        map<int, pair<int,int>>mp; 
        int i = 0 ;
        for(auto it: strs){
            int zero = 0, one = 0 ;    
            for(auto ch: it){
                if(ch == '1')
                    one ++ ;
                else
                    zero ++ ;
            }
            mp[i] = {zero, one} ;
            i++ ;
        }
        vector<vector<vector<int>>>dp(len+1, vector<vector<int>>(m+1, vector<int>(n+1 ,0))) ;
        
        for(int i = 1 ; i <= len; i++){
             int ones = mp[i-1].second , zeros = mp[i-1].first ;
            for(int j = 0 ; j<= m ;j++){
                for(int k = 0 ; k <= n; k++){
                   
                    if(j - zeros >=0 and k - ones >= 0)
                        dp[i][j][k] = max(dp[i-1][j][k], 1+dp[i-1][j-zeros][k-ones]) ;
                    else
                        dp[i][j][k] = dp[i-1][j][k] ;
                }
            }
        }
        return dp[len][m][n] ;
    }
};