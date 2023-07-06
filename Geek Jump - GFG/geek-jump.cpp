//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> dp;
    int f(int n, vector<int>& h) {
        if(n == 0) return 0;
        
        if(dp[n] != -1) return dp[n];
        
        int op1 = INT_MAX, op2 = INT_MAX;
        if(n - 1 >= 0) op1 = abs(h[n] - h[n-1]) + f(n-1, h);
        if(n - 2 >= 0) op2 = abs(h[n] - h[n-2]) + f(n-2, h);
        
        return dp[n] = min(op1, op2);
    }
    
    int minimumEnergy(vector<int>& h, int n) {
        // Code here
        dp.resize(n+1, -1);
        return f(n-1, h);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends