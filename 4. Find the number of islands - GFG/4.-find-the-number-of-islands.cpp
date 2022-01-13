// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int cnt = 0;
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<bool>> vis(m, vector<bool>(n, 0));
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1' and !vis[i][j]){
                    dfs(m, n, i, j, vis, grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
    
    bool  isSafe(int row, int col, int m, int n, vector<vector<bool>> &vis, vector<vector<char>> &grid){
        return ((row>=0 and row<m) and (col>=0 and col<n) and (grid[row][col]=='1' and !vis[row][col]));
    }
    
    void dfs(int m, int n, int row, int col, vector<vector<bool>> &vis, vector<vector<char>> &grid){
        static int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1};
        static int dy[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        
        vis[row][col] = true;
        
        for(int i=0; i<8; i++){
            if(isSafe(row+dx[i], col+dy[i], m, n, vis, grid))
                dfs(m, n, row+dx[i], col+dy[i], vis, grid);
        }
    }
    
    
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends