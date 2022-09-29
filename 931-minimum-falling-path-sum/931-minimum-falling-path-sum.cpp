class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int ans = 1e9;
        vector<int> prev(n);
        for(int i=0; i<n; i++) {
            prev[i] = mat[n-1][i];
        }
        
        for(int i=n-2; i>=0; i--) {
            vector<int> curr(n);
            for(int j=n-1; j>=0; j--) {
                int op1 = 1e9, op2 = 1e9, op3 = 1e9;
                if(j-1 >= 0) {
                    op1 = prev[j-1];
                }
                if(j+1 < n) {
                    op2 = prev[j+1];
                }
                op3 = prev[j];
                curr[j] = mat[i][j] + min(op1, min(op2, op3));
            }
            prev = curr;
        }
        
        for(int i=0; i<n; i++) {
            ans = min(ans, prev[i]);
        }
        return ans;
    }
};