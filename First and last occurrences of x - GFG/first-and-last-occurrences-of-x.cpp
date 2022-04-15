// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    // code here
    auto it1 = lower_bound(arr, arr+n, x);
    auto it2 = upper_bound(arr, arr+n, x);
    
    int a = it1-arr;
    int b = it2-arr;
    if(a == b){
        return{-1, -1};
    }
    else{
        return{a, b-1};
    }
    
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


  // } Driver Code Ends