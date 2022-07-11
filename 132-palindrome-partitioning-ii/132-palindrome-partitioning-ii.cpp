class Solution {
public:
    int dp[2001][2001];
    int minCut(string str) {
        memset(dp, -1, sizeof(dp));
        int n = str.size();
        return solve(str, 0, n-1);
    }
    
    int solve(string &str, int i, int j) {
        if(i > j) {
            return 0;
        }
        
        if(isPalindrome(str, i, j)) {
            return 0;
        }
        
        if(dp[i][j]!=-1) {
            return dp[i][j];
        }
        
        int ans = INT_MAX;
        for(int k=i; k<j; k++) {
            if(isPalindrome(str, i, k)) {
                ans = min(ans, 1 + solve(str, k+1, j));
            }            
        }
        return dp[i][j] = ans;
    }
    
    bool isPalindrome(string &str, int i, int j) {
        while(i<=j) {
            if(str[i++] == str[j--]) continue;
            else return false;
        }
        
        return true;
    }
};