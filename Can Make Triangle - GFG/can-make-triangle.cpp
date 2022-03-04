// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<int> canMakeTriangle(vector<int> arr, int N){
        // code here
        vector<int>ans(N-2, 0);
       if(N<3)
           return ans;
       int a, b, c;
       int count=0;
       for(int i=2;i<N;i++){
           a = arr[i-2];
           b = arr[i-1];
           c = arr[i];
           
           if((a+b<=c) || (b+c<=a) || (c+a<=b)){
               ++count;
               continue;
           }
           else
               ans[count++] = 1;
       }
       return ans;
    }
}; 

// { Driver Code Starts.
int main() 
{ 
    int t;cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        vector<int> A(N);
        for(int i=0;i<N;i++)
            cin>>A[i];
        Solution ob;
        auto ans = ob.canMakeTriangle(A, N);
        for(int i=0;i<ans.size();i++)
            cout << ans[i] << " ";
        cout << endl;
        
    }

    return 0; 
}   // } Driver Code Ends