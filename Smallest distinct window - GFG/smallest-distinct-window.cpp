// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here   
        unordered_set<char> s(str.begin(), str.end());
        int n = s.size();
        int st=0,ans=str.size();
        unordered_map<char,int> mp;
        for(int i=0;i<str.size();i++){
            mp[str[i]]++;
            while(mp.size()==n){
                ans = min(ans, i - st + 1);
                mp[str[st]]--;
                if(mp[str[st]]==0) mp.erase(str[st]);
                st++;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}  // } Driver Code Ends