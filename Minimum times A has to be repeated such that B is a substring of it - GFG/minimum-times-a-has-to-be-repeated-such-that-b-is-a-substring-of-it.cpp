// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minRepeats(string a, string b) {
        // code here
        const int mod = 1e4;
        string s = a;
        int cnt = 1;
        if(a.find(b)!=string::npos){
            return cnt;
        }
        
        int n = s.length();
        while(n<mod){
            s += a;
            n = s.length();
            ++cnt;
           
            if(s.find(b)!=string::npos){
                return cnt;   
            }
            
        }
        return -1;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}  // } Driver Code Ends