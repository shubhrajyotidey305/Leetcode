// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
public:
	int FindWays(int n, int m, vector<vector<int>>blocked_cells){
	    // Code here
	    int MOD = 1e9+7;
	    vector<vector<int>> grid(n+1,vector<int>(m+1,0));
        for(int i=0; i<blocked_cells.size();i++)
        grid[blocked_cells[i][0]][blocked_cells[i][1]] = -1;
            
        vector<int> prev(m+1,0);
        for(int i=1; i<=n; i++){
            vector<int> curr(m+1,0);
            for(int j=1; j<=m;j++){
                if(grid[i][j]==-1) curr[j]=0;
                else if(i==1 and j==1) curr[j]=1;
                else{
                    int up = prev[j];
                    int left = curr[j-1];
                    curr[j] = (up+left)%MOD;
                }
            }
            prev = curr;
        }
        return prev[m];
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, k;
		cin >> n >> m >> k;
		vector<vector<int>>blocked_cells;
		for(int i = 0; i < k; i++){
			int x, y;
			cin >> x >> y;
			blocked_cells.push_back({x, y});
		}
		Solution obj;
		int ans = obj.FindWays(n, m, blocked_cells);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends