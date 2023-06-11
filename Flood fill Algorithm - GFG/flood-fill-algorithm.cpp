//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int color) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        queue<pair<int, int>> q;
        q.push({sr, sc});
        int col = grid[sr][sc];
        grid[sr][sc] = color;

        while(!q.empty()) {
            int a = q.front().first;
            int b = q.front().second;

            q.pop();
            for(int i=0; i<4; i++) {
                int na = a + dx[i];
                int nb = b + dy[i];

                if(na >= 0 and na < n and nb >= 0 and nb < m and grid[na][nb] == col and grid[na][nb] != color) {
                    grid[na][nb] = color;
                    q.push({na, nb});
                }
            }
        }
        return grid;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends