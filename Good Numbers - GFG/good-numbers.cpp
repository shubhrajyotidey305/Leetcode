//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> goodNumbers(int l, int r, int d) {
        // code here
        vector<int> ans;
        for(int i=l; i<=r; i++) {
            if(isGood(i, d)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
    
    bool isGood(int num, int d) {
        int digit = num % 10;
        if(digit == d) return false;
        int sum = digit;
        num /= 10;
        
        while(num > 0) {
            digit = num % 10;
            if(digit == d or digit <= sum) return false;
            
            num /= 10;
            sum += digit;
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int L, R, D;
        cin >> L >> R >> D;
        Solution ob;
        vector<int> ans = ob.goodNumbers(L, R, D);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}
// } Driver Code Ends