//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> dp;
    int mod = 1e8;
    int solve(int n) {
        if(n == 0) {
            return 1;
        }
        
        if(dp[n] != -1) {
            return dp[n];
        }
        
        int op1, op2;
        op1 = op2 = 0;
        
        if(n-1 >= 0) {
            op1 = solve(n-1);
        }
        
        if(n-2 >= 0) {
            op2 = solve(n-2);
        }
        
        return dp[n] = (op1 + op2) % mod;
    }
    int fillingBucket(int N) {
        // code here
        dp.assign(N+1, -1);
        return solve(N);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends