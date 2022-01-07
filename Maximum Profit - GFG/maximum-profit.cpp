// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int k, int n, int a[]) {
        // code here
        
        vector<vector<int>> dp(k+1, vector<int>(n, 0));
        
        for(int t=1; t<=k; t++){
            for(int d=1; d<n; d++){
                int maxi = dp[t][d-1];
                
                
                for(int pd = 0; pd<d; pd++){
                    int pf = dp[t-1][pd];
                    int pth = a[d] - a[pd];
                    
                    if(pf + pth > maxi){
                        maxi = pf + pth;
                    }
                }
                
                dp[t][d] = maxi;
            }
        }
        
        return dp[k][n-1];
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends