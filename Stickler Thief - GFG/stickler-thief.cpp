//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    vector<int> dp;
    int f(int arr[], int n) {
        if(n == 0) return arr[0];
        
        if(dp[n] != -1) return dp[n];
        
        int op1 = arr[n];
        if(n-2 >= 0) op1 += f(arr, n-2);
        
        int op2 = 0;
        if(n-1 >= 0) op2 += f(arr, n-1);
        
        return dp[n] = max(op1, op2);
    }
    
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        dp.resize(n, -1);
        return f(arr, n-1);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends