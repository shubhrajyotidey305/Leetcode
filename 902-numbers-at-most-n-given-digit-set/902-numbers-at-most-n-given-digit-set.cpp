class Solution {
public:
    int dp[15][2][2];
    int atMostNGivenDigitSet(vector<string>& arr, int n) {
        string num = to_string(n);
        n = num.size();
        vector<int> digits(arr.size());
        
        for(int i=0; i<arr.size(); i++) {
            digits[i] = arr[i][0] - '0';
        }
        memset(dp, -1, sizeof dp);
        return solve(num, n, 0, 1, digits) - 1;
    }
    
    int solve(string &num, int n, int start, bool tight, vector<int>& digits) {
        if(n == 0) {
            return 1;
        }
        
        if(dp[n][start][tight] != -1) {
            return dp[n][start][tight];
        }
        
        int ans = 0;
        if(start) {
            int ub = tight ? num[num.length()-n]-'0' : 9;
            for(int dig : digits) {            
                if(dig <= ub) {
                    ans += solve(num, n-1, start, tight & (dig == ub), digits);
                }
            }            
        } else {
            int ub = tight ? num[num.length()-n]-'0' : 9;
            ans = solve(num, n-1, 0, 0, digits);
            for(int dig : digits) {            
                if(dig <= ub) {
                    ans += solve(num, n-1, 1, tight & (dig == ub), digits);
                }
            }
        }     
        return dp[n][start][tight] = ans;
    }
};