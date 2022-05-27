// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> numAndDen(int n, int d) {
        // code here
        int cn = 10000, cd = 10000, bn = cn, bd = cd ;
        double rr = (double)n/d , cr = (double)cn/cd , best_error = 100000 ;
        
        while(cn >= 1  && cd >= 1){
            while(cr >= rr)
                cn-- , cr = (double)cn/cd ;
            
            while(cr < rr)
                cd-- , cr = (double)cn/cd ;
            
            if(rr - (double)cn/(cd+1) < best_error)
                bn = cn, bd = cd+1, best_error = rr - (double)cn/(cd+1) ;
        }
        
        int gcd = __gcd(bn,bd) ;
        return vector<int>( { bn/gcd, bd/gcd }) ;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,d;
        cin >> n >> d;
        Solution ob;
        vector<int>ans=ob.numAndDen(n,d);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
  // } Driver Code Ends