// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int longestSubstring(string s) {
        // code here
        int result = 0, mask=0;; 
        map<int, int> m;         
        m[mask] = -1;
        for(int i=0;i<s.size(); i++){ 
            int t=s[i]-'a';
            mask^=(1<<t);
            if (m[mask]) result = max(result,i - m[mask]);
            else m[mask] = i;
            for(int j = 0; j < 26; j++){ 
                int mask2 = mask^(1<<j);
                if (m[mask2]) result =max(result,i - m[mask2]);
            }
        }
        return result;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;

        Solution ob;
        cout << ob.longestSubstring(S) << endl;
    }
    return 0;
}  // } Driver Code Ends