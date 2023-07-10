//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
	#define pii pair<int, pair<int, int>>
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        int n = grid.size();
        vector<vector<int>> dist (n, vector<int>(n, INT_MAX));
        dist[0][0] = grid[0][0];
        
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({dist[0][0], {0, 0}});
        
        while(!pq.empty()) {
            int val = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            
            pq.pop();
            
            if(x == n-1 and y == n-1) {
                return val;
            }
            
            for(int i=0; i<4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx >= 0 and nx < n and ny >= 0 and ny < n) {
                    int ndist = val + grid[nx][ny];
                    if(ndist < dist[nx][ny]) {
                        dist[nx][ny] = ndist;
                        pq.push({ndist, {nx, ny}});
                    }   
                }
                
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends