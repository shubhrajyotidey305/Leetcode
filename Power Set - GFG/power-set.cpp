//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    void f(int i, int n, string s, string &str, vector<string> &ans) {
	        if(i == n) {
	            if(!s.empty()) ans.push_back(s);
	            return;
	        }    
	        
	        f(i+1, n, s, str, ans);
	        f(i+1, n, s + str[i], str, ans);
	    }
	    
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string> ans;
		    f(0, s.size(), "", s, ans);
		    sort(ans.begin(), ans.end());
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends