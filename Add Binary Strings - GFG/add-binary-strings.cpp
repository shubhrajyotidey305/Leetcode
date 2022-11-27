//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	string addBinary(string a, string b)
	{
	    // your code here
	    int i = a.size()-1;
	    int j = b.size()-1;
	    int sum = 0;
	    int c = 0;
	    string ans = "";
	    while(i >= 0 && j >= 0)
	    {
	        sum = (a[i--]-'0')+(b[j--]-'0')+c;
	        c = sum>>1;
	        sum = sum&1;
	        ans.push_back(sum+'0');
	    }
	    while(i >= 0)
	    {
	        sum = (a[i--]-'0')+c;
	        c = sum>>1;
	        sum = sum&1;
	        ans.push_back(sum+'0');
	    }
	    while(j >= 0)
	    {
	        sum = (b[j--]-'0')+c;
	        c = sum>>1;
	        sum = sum&1;
	        ans.push_back(sum+'0');
	    }
	    if(c == 1) ans.push_back('1');
	    while(ans.back() == '0')ans.pop_back();
	    reverse(ans.begin(), ans.end());
	    return ans;
	}
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string A, B; cin >> A >> B;
		Solution ob;
		cout << ob.addBinary (A, B);
		cout << "\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends