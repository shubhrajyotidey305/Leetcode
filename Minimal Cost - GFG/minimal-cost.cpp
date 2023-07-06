//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> dp;
    int f(vector<int> &h, int n, int k) {
        if(n == 0) {
            return 0;
        }    
        
        if(dp[n] != -1) return dp[n];
        
        int op = INT_MAX;
        for(int i=1; i<=k; i++) {
            if(n - i >= 0) {
                op = min(op, abs(h[n] - h[n-i]) + f(h, n-i, k));
            }
        }
        return dp[n] = op;
    }
    
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        dp.resize(n, -1);
        return f(height, n-1, k);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends