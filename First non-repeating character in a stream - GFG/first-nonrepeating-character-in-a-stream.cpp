// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
	string FirstNonRepeating(string s){
        // Code here
        vector<int> mark(26, 0);
        queue<int> q;
        
        string res = "";
        
        for(auto it:s){
            int idx = it-'a';
            
            if(mark[idx] == 1){
                // code
                mark[idx]++;
                
            }
            
            else if(mark[idx] == 0){
                // code
                mark[idx]++;
                q.push(it);
            }
            
            while(!q.empty() and mark[q.front()-'a'] == 2){
                q.pop();
            }
            
            if(q.empty()){
                res.push_back('#');
            }
            else{
                res.push_back(q.front());
            }
        }
        
        return res;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends