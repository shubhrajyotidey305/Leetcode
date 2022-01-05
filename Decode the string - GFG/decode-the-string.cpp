// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        // code here
        stack<int> intpack;
        stack<char> charpack;
        
        string temp = "", res = "";
        
        for(int i=0; i<s.size(); i++){
            int cnt = 0;
            
            if(s[i]>='0' and s[i]<='9'){
                while(s[i]>='0' and s[i]<='9'){
                    cnt = cnt*10 + s[i]-'0';
                    i++;
                }
                i--;
                intpack.push(cnt);
            }
            else if(s[i]==']'){
                temp = "";
                cnt = 0;
                
                if(!intpack.empty()){
                    cnt = intpack.top();
                    intpack.pop();
                }    
                
                while(!charpack.empty() and charpack.top()!='['){
                    temp = charpack.top() + temp;
                    charpack.pop();
                }
                
                if(!charpack.empty() and charpack.top()=='[')
                    charpack.pop();
                
                for(int j=0; j<cnt; j++){
                    res += temp;
                }
                
                for(int j=0; j<res.size(); j++){
                    charpack.push(res[j]);
                }
                
                res = "";
            }
            else if(s[i]=='['){
                if(s[i-1]>='0' and s[i-1]<='9'){
                    charpack.push(s[i]);
                }    
                else{
                    charpack.push(s[i]);
                    intpack.push(1);
                }
            }
            else{
                charpack.push(s[i]);
            }
        }
        
        while(!charpack.empty()){
            res = charpack.top() + res;
            charpack.pop();
        }
        return res;
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}  // } Driver Code Ends