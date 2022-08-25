class Solution {
public:
    int uniquePaths(int a, int b) {
        vector<int> dp(b,0);
        dp[b-1] = 1;

        for(int i=a-1; i>=0; i--) {
            vector<int> temp(b,0);
            for(int j=b-1; j>=0; j--) {
                if(i == a-1 and j == b-1) {
                    temp[j] = 1;
                    continue;
                }
                int op1 = 0, op2 = 0;
                if(i+1 < a) {
                    op1 = dp[j];
                }
                if(j+1 < b) {
                    op2 = temp[j+1];
                }
                temp[j] = op1 + op2;
            }
            dp = temp;
        }
        return dp[0];
    }
};