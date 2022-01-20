// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int v, vector<int> adj[])
    {
        //code here
        stack<int> st;
        bool vis[v] = {0};
        
        for(int i=0; i<v; i++){
            if(!vis[i]){
                toposort(adj, st, vis, i);    
            }
        }
        
        
        vector<int> trans[v];
        transpose(v, trans, adj);
        for(int i=0; i<v; i++) vis[i] = false;
        
        int cnt = 0;
        while(!st.empty()){
            int u = st.top();
            st.pop();
            
            if(!vis[u]){
                dfs(trans, vis, u);
                cnt++;
            }
        }
        return cnt;
        
    }
    
    void dfs(vector<int>trans[], bool vis[], int s){
        vis[s] = true;
        
        for(auto u:trans[s]){
            if(!vis[u]){
                dfs(trans, vis, u);
            }
        }
    }
    
    void transpose(int v, vector<int> trans[], vector<int> adj[]){
        for(int i=0;i<v;i++){
            for(auto u:adj[i]){
                trans[u].push_back(i);
            }
        }
    }
    
    void toposort(vector<int> adj[], stack<int> &st, bool vis[], int s){
        vis[s] = true;
        
        for(auto u:adj[s]){
            if(!vis[u]){
                toposort(adj, st, vis, u);
            }
        }
        st.push(s);
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends