// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> adj[])
    {
        // code here
        int res = 0;
        
        int key[v];
        fill(key, key+v, INT_MAX);
        key[0] = 0;
        
        bool mset[v] = {0};
        
        for(int cnt=0; cnt<v; cnt++){
            int u = -1;
            for(int i=0; i<v; i++){
                if(!mset[i] and (u==-1 or key[i]<key[u])){
                    u = i;
                }
            }
            
            mset[u] = true;
            res += key[u];
            
            for(auto it:adj[u]){
                if(!mset[it[0]]){
                    key[it[0]] = min(key[it[0]], it[1]);
                }
            }
        }
        return res;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends