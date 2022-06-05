// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long buzzTime(long N, long M, long L, long H[], long A[])
    {
        // code here
        long mini = INT_MAX;
        for(int i=0;i<N;i++){
            long x=ceil(((float)L-(float)H[i])/(float)A[i]);
            mini=min(x,mini);
        }
        
        while(true){
            int sum=0;
            for(int i=0;i<N;i++){
                if(H[i]+(A[i]*mini)>=L){
                    sum+=H[i]+(A[i]*mini);
                }
                if(sum>=M)return mini;
            }
            mini++;
        }
        return 0;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long N, M, L;
        cin>>N>>M>>L;
        long H[N], A[N];
        for(long i = 0;i < N;i++) 
            cin>>H[i]>>A[i];
        
        Solution ob;
        cout<<ob.buzzTime(N, M, L, H, A)<<"\n";
    }
    return 0;
}  // } Driver Code Ends