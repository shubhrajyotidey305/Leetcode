// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    string chooseandswap(string s){
        // Code Here
        int n = s.size();
        vector<int> mark(26, -1);
        
        for(int i=0; i<n; i++){
            if(mark[s[i]-'a'] == -1){
                mark[s[i]-'a'] = i;
            }
        }
        
        int i = 0, j;
        for(; i<n; i++){
            bool fl = false;
            
            for(j=0; j<s[i] - 'a'; j++){
                if(mark[j] > mark[s[i] - 'a']){
                    fl = true;
                    break;
                }
            }
            
            if(fl) break;
        }
        
        if(i<n){
            char c1 = s[i];
            char c2 = (char) j + 'a';
            
            for(int i=0; i<n; i++){
                if(s[i] == c1) s[i] = c2;
                else if(s[i] == c2) s[i] = c1;
            }
        }
        return s;
        
    }
    
};


// { Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}
  // } Driver Code Ends