// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int dp[105][10005];
    int solve(vector<int> &arr, int n, int sum){
        if(n == 0){
            if(sum == 0) return 1;
            else return 0;
        }
        
        if(dp[n][sum] != -1) return dp[n][sum];
        
        if(arr[n-1] <= sum) return dp[n][sum] = (solve(arr, n-1, sum-arr[n-1]) || solve(arr, n-1, sum)); 
        else return dp[n][sum] = solve(arr, n-1, sum);
    }
    
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        memset(dp, -1, sizeof(dp));
        return solve(arr, arr.size(), sum);
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends