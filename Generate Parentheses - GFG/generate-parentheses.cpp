//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    void f(int n, int count, string &s, vector<string> &ans) {
        if(n == 0 and count == 0) {
            ans.push_back(s);
            return;
        }    
        
        if(n > 0) {
            s += '(';
            f(n-1, count + 1, s, ans);
            s.pop_back();
        } 
        
        if(count > 0) {
            s += ')';
            f(n, count - 1, s, ans);
            s.pop_back();
        }
        
    }
    
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        vector<string> ans;
        string s = "";
        f(n, 0, s, ans);
        return ans;
    }
};

//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends