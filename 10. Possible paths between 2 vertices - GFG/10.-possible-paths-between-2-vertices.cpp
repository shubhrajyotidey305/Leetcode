// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to count paths between two vertices in a directed graph.
    int countPaths(int v, vector<int> adj[], int s, int d) {
        // Code here
        int cnt = 0;
        dfs(cnt, adj, s, d);
        return cnt;
    }
    
    void dfs(int &cnt, vector<int> adj[], int s, int d){
        if(s == d){
            cnt++;
            return;
        }
        
        for(auto u:adj[s]){
            dfs(cnt, adj, u, d);
        }
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // adj[v].push_back(u);
        }
        int source, destination;
        cin >> source >> destination;
        Solution obj;
        cout << obj.countPaths(V, adj, source, destination) << endl;
    }
    return 0;
}  // } Driver Code Ends