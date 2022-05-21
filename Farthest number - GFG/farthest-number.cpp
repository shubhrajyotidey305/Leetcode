// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{   
  public:
    vector<int> farNumber(int n,vector<int> arr){
        //code here
        vector<pair<int, int>> v;
        v.push_back({arr[n-1], n-1});
        
        arr[n-1] = -1;
        for(int i=n-2; i>=0; i--){
            int mx = -1, low = 0, high = v.size() - 1;
            while(low<=high){
                int mid = (low + high) / 2;
                if(v[mid].first < arr[i]){
                    mx = v[mid].second;
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            if(mx == -1){
                v.push_back({arr[i], i});
            }
            arr[i] = mx;
        }
        return arr;
    }
};

// { Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++)
            cin>>Arr[i];
        Solution obj;
        vector<int> answer=obj.farNumber(N,Arr);
        for(auto i:answer)
            cout<<i<<" ";
        cout<<endl;
  }
}  // } Driver Code Ends