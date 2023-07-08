//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    const int mod = 1e9 + 7;
    vector<vector<int>> dp;
    int f(int n, int m, vector<vector<int>> &grid) {
        if(n == 0 and m == 0) return 1; 
        
        if(dp[n][m] != -1) return dp[n][m];
        
        int op1 = 0, op2 = 0;
        if(n-1 >= 0 and grid[n-1][m] == 0) op1 += f(n-1, m, grid)%mod;
        if(m-1 >= 0 and grid[n][m-1] == 0) op2 += f(n, m-1, grid)%mod;
        
        return dp[n][m] = (op1 + op2)%mod;
    }
    
    int totalWays(int n, int m, vector<vector<int>>& grid) {
        // Code here
        if(grid[n-1][m-1] != 0 or grid[0][0] != 0) return 0;
        dp = vector<vector<int>> (n, vector<int> (m, -1));
        return f(n-1, m-1, grid);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < m; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.totalWays(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends