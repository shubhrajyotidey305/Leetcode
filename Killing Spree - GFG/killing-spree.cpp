// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
public:
    long long int killinSpree(long long int n)
    {
        // Code Here
        long long count = 0 ;
       int i = 1 ;
       while(n>0)
       {
           if(n>=i*i)
           {
               n -= i*i ;
               count++ ;
           }
           else{
               break ;
           }
           
           i++ ;
       }
       
       return count ;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n; cin>>n;
        Solution obj;
        long long int ans = obj.killinSpree(n);
        cout<<ans<<"\n";
    }
    return 0;
}
  // } Driver Code Ends