// { Driver Code Starts
#include <bits/stdc++.h>
#define N 10000
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    vector<int> print_next_greater_freq(int arr[],int n)
    {
        // code here
        unordered_map<int,int> s;
        for(int i=0;i<n;i++)
            s[arr[i]]++;
        stack<int> a;
        vector<int> a1;
        a1.push_back(-1);
        a.push(arr[n-1]);
        for(int i=n-2;i>=0;i--)
        {
            if(a.empty())
            {
                a1.push_back(-1);
                a.push(arr[i]);
                continue;
            }
            if(s[arr[i]]<s[a.top()])
            {
                a1.push_back(a.top());
                a.push(arr[i]);
            }
            else
            {
                while(!a.empty() && s[arr[i]]>=s[a.top()])
                    a.pop();
                if(a.empty())
                    a1.push_back(-1);
                else
                    a1.push_back(a.top());
                a.push(arr[i]);
            }
        }
        reverse(a1.begin(),a1.end());
        return a1;
    }
};


// { Driver Code Starts.

int main()
{
    int arr[N];
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        for(int i=0; i<n; i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans=ob.print_next_greater_freq(arr,n);
        for(auto x:ans){
            cout<<x<<" ";
        }
        cout << endl;
    }
	return 1;
}
  // } Driver Code Ends