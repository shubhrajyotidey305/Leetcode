// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    int n;
    
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        n = grid.size();
        
        vector<vector<bool>> vis(n, vector<bool>(n, 0));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    if(dfs(i, j, grid, vis)){
                        return true;   
                    }
                }
            }
        }
        return false;
        
    }
    
    bool isSafe(int row, int col, vector<vector<int>> &grid, vector<vector<bool>> &vis){
        return ((row>=0 and row<n) and (col>=0 and col<n) and (grid[row][col] !=0 and !vis[row][col]));
    }
    
    bool dfs(int row, int col, vector<vector<int>> &grid, vector<vector<bool>> &vis){
        vis[row][col] = true;
        if(grid[row][col] == 2) return true;
        
        static int rownum[] = {-1, 1, 0 ,0};
        static int colnum[] = {0, 0, 1, -1};
        
        // call for dfs of source's adjacent
        for(int i=0; i<4; i++){
            if(isSafe(row+rownum[i], col+colnum[i], grid, vis)){
                if(dfs(row+rownum[i], col+colnum[i], grid, vis)){
                    return true;
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.
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
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends