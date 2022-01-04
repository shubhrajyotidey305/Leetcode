// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
	int CountWays(string s){
        // Code here
        if(s[0]=='0')
            return 0;
        
        const int m = 1e9+7;
        
        int n = s.size();
        vector<long long> cnt(n+1);
        
        cnt[0] = 1;
        cnt[1] = 1;
        
        for(int i=2; i<=n; i++){
            cnt[i] = 0;
            
            if(s[i-1]>'0'){
                cnt[i] = cnt[i-1];
            }
            
            if(s[i-2]=='1' or (s[i-2]=='2' and s[i-1]<'7')){
                cnt[i] = (cnt[i] + cnt[i-2])%m;
            }
        }
        
        return cnt[n]%m;
        
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends