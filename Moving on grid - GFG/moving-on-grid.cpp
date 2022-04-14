// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string movOnGrid(int r, int c) {
        // code here
        r--;
        c--;
        r = r%7;
        c = c%4;
        if(r == c){
            return "ARYA";
        }
        return "JON";
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;
        Solution ob;
        cout<<ob.movOnGrid(r,c)<<endl;
    }
    return 0;
}
  // } Driver Code Ends