// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxCoins(int a[], int b[], int t, int n) {
        // code here
        vector<pair<int, int>> arr;
        
        for(int i = 0; i < n; i++) arr.push_back({b[i], a[i]});
        sort(arr.begin(), arr.end());
        
        int ans = 0;
        for(int i = n - 1; i >= 0; i--) {
            int curr = min(t, arr[i].second);
            ans += curr * arr[i].first;
            t -= curr;
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int T,N;
        cin>>T>>N;
        
        int A[N], B[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<N; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.maxCoins(A,B,T,N) << endl;
    }
    return 0;
}  // } Driver Code Ends