//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int dp[5][2];
    int solve(int i, bool tight, string &s) {
        if(i == s.size()) {
            return 1;
        }
        
        if(dp[i][tight] != -1) {
            return dp[i][tight];
        }
        
        int ub = tight ? s[i] - '0' : 9;
        int ans = 0;
        for(int j=0; j<=ub; j++) {
            if(j != 3) {
                ans += solve(i+1, tight & (j == ub), s);   
            }
        }
        return dp[i][tight] = ans;
    }
    int count(int n){
        // code here
        string s = to_string(n);
        memset(dp, -1, sizeof dp);
        return solve(0, 1, s) - 1;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.count(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends