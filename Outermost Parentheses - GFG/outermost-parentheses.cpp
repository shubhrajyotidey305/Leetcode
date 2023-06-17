//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string removeOuter(string& s) {
        // code here
        stack<char> st;
        string res;
        
        for(int i=0; i<s.size(); i++) {
            if(!st.empty()) {
                res += s[i];
            }
            
            if(s[i] == '(') {
                st.push(s[i]);
            } else {
                st.pop();
            }
            
            if(st.empty()) {
                res.pop_back();
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;

        cout << obj.removeOuter(s) << "\n";
    }
}
// } Driver Code Ends