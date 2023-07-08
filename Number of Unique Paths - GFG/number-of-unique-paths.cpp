//{ Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    //Function to find total number of unique paths.
    vector<vector<int>> dp;
    int f(int x, int y) {
        if(x == 0 and y == 0) {
            return 1;
        }    
        
        if(dp[x][y] != -1) return dp[x][y];
        
        int op1 = 0, op2 = 0;
        
        if(y-1 >= 0) op1 = f(x, y-1);
        if(x-1 >= 0) op2 = f(x-1, y);
        return dp[x][y] = op1 + op2;
    }
    
    int NumberOfPath(int a, int b)
    {
        //code here
        dp = vector<vector<int>> (a, vector<int>(b, -1));
        return f(a-1, b-1);
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
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}


// } Driver Code Ends