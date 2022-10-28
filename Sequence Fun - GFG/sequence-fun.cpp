//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
	public:
	#define ll long long
	int mod = 1e9 + 7;
	int NthTerm(int n){
	    // Code  here
	    ll i = 2;
	    ll j = 2;
	    
	    for(int k=1; k<n; k++) {
	        j = (j*i + 1)%mod;
	        i++;
	    }
	    return j;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution obj;
		int ans = obj.NthTerm(n);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends