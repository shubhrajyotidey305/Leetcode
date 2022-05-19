// { Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    int transform (string a, string b)
    {
        //code here.
        unordered_map<char,int> f ;
        for(auto &x: a)
            f[x]++ ;
        for(auto &x: b)
            f[x]-- ;
        
        for(auto &p: f){
            if(p.second != 0)
                return -1 ;
        }
        
        int ans = 0, n = a.size(), i=n-1, j=n-1 ;
        while(i>=0){
            while(i>=0 && a[i] == b[j])
                i--,j-- ;
            
            while(i>=0 && a[i] != b[j])
                i--, ans++ ;
        }
        return ans;
    }
};


// { Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}  // } Driver Code Ends