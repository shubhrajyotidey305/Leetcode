//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int f(int i, int j, string &s) {
        if(i > j) {
            return 0;
        }
        
        int ans = f(i, j-1, s) * 10 + s[j] - '0';
        return ans;
    }
    
    int atoi(string s) {
        //Your code here
        int n = s.size(), i = 0, sign = 1;
        
        while(s[i] == ' ') i++;
        
        if(s[i] == '-') {
            sign = -1;
            i++;
        } else if(s[i] == '+') {
            i++;
        }
        
        for(int j=i; j<n; j++) {
            if(!isdigit(s[j])) return -1;
        }
        return sign*f(i, n-1, s);
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends