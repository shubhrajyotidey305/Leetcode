// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void solve(int idx, int m, string& s, unordered_set<string>& dict, string temp, vector<string>& ans){
       if(idx==m){
           temp.pop_back(); // to remove extra space at end
           ans.push_back(temp);
           return;
       }
       for(int i=1;i<=m-idx;i++){
           if(dict.count(s.substr(idx, i))){
               solve(idx+i, m, s, dict, temp+s.substr(idx, i)+" ", ans);
           }
       }
   } 
   vector<string> wordBreak(int n, vector<string>& dict, string s)
   {
       string temp = "";
       int m = s.size();
       vector<string>ans;
       unordered_set<string>st;
       for(auto i : dict){
           st.insert(i);
       }
       solve(0, m, s, st, temp, ans);
       return ans;
       // code here
   }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends