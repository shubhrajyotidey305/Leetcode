//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        long long int now=0;
        for(long long int i=0;i<N;i++)
        {
            now^=Arr[i];
        }
        
        for(int i=0;i<32;i++)
        {
            long long int k=(1<<i);
            if((k&now)==0)
                continue;
            
            long long int a=0;
            long long int b=0;
            
            for(long long int i=0;i<N;i++)
            {
                if((Arr[i]&k)==0)
                    a^=Arr[i];
                else
                    b^=Arr[i];
            }
            vector<long long int> ans={max(a,b),min(a,b)};
            return ans;
        }
        return {0,0};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends