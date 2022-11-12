//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int find(string s,int n,int k ,char c){
	        int l=0,r=0;
	        int len=1;
	        int ct=0;
	        while(r<n){
	            if(s[r]!=c) ct++;
	            while(ct>k){
	                if(s[l]!=c) ct--;
	                l++;
	            }
	            len=max(len,r-l+1);
	            r++;
	        }
	        return len;
	    }
		int characterReplacement(string s, int k){
		   int n=s.length();
		   int maxlen=1;
		   for(int i=0;i<26;i++)
		    maxlen=max(maxlen,find(s,n,k,i+'A'));
		   
		   return maxlen;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		int k;
		cin >> k;
		Solution obj;
		int ans = obj.characterReplacement(s, k);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends