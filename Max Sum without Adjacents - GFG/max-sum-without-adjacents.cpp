//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	vector<int> dp;
	int f(int *arr, int n) {
	    if(n == 0) return arr[0];
	    
	    if(dp[n] != -1) return dp[n];
	    
	    int op1 = arr[n], op2 = 0;
	    if(n-2 >= 0) op1 += f(arr, n-2);
	    if(n-1 >= 0) op2 += f(arr, n-1);
	    return dp[n] = max(op1, op2);
	}
	
	int findMaxSum(int *arr, int n) {
	    // code here
	    dp.resize(n, -1);
	    return f(arr, n-1);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends