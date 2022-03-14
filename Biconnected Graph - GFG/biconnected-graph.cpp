// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int biGraph(int arr[], int n, int e) {
        // code here
        vector<vector<int>> adj(n) ;
        
        for(int i=0;i<2*e;i+=2)
        {
            int u = arr[i] , v = arr[i+1] ;
            
            adj[u].push_back(v) ; adj[v].push_back(u) ;
        }
        
        for(int curr = 0 ;curr<n;curr++)
        {
            if(adj[curr].size()==0)
                {
                    if(n==1)
                        continue ;
                    else
                        return 0 ;
                }
                
            set<int> st ; // neighbours of current node
            
            for(auto x : adj[curr])
            {
                st.insert(x) ;
            }
            
            queue<int> q ; q.push(*st.begin()) ;  st.erase(st.begin()) ;
            vector<bool> vis(n,false) ;
            
            vis[curr] = vis[q.front()] = true ;
            
            while(!q.empty() && !st.empty())
            {
                int x = q.front() ; q.pop() ;
                
                for(auto y : adj[x])
                {
                    if(vis[y])
                        continue ;
                    
                    q.push(y) ; vis[y] = true ;
                    
                    if(st.find(y)!=st.end())
                        st.erase(st.find(y)) ;
                }
            }
            
            if(!st.empty())
                return 0 ;
        }
        
        return 1 ;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,e;
        cin>>n>>e;
        
        int arr[2*e];
        for(int i=0; i<2*e; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.biGraph(arr,n,e) << endl;
    }
    return 0;
}  // } Driver Code Ends