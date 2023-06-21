//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool isOdd (char ch) {
        int digit = ch - '0';
        return (digit % 2);
    }
    
    string maxOdd(string s) {
        // your code here
        int n = s.size(), idx = -1;
        for(int i=n-1; i>=0; i--) {
            if(isOdd(s[i])) {
                idx = i;
                break;
            }
        }

        return s.substr(0, idx+1);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;

        cout << ob.maxOdd(s) << endl;
    }
}

// } Driver Code Ends