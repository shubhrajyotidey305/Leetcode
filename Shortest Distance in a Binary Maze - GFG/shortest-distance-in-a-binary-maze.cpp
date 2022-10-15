//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {

  public:

    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {

        // code here
        if (source.first == destination.first && source.second == destination.second)
            return 0;

        queue<pair<int, int>> q;

        q.push(source);

        int n = grid.size(), m = grid[0].size();

        while (q.size() > 0) {

            int i = q.front().first;

            int j = q.front().second;

            if (i == destination.first && j == destination.second)

                return grid[i][j] - 1;

            if (i >= 1 && grid[i - 1][j] == 1) {

                q.push(pair<int, int>(i - 1, j));

                grid[i - 1][j] = grid[i][j] + 1;

            }

            if (i < n - 1 && grid[i + 1][j] == 1) {

                q.push(pair<int, int>(i + 1, j));

                grid[i + 1][j] = grid[i][j] + 1;

            }

            if (j >= 1 && grid[i][j - 1] == 1) {

                q.push(pair<int, int>(i, j - 1));

                grid[i][j - 1] = grid[i][j] + 1;

            }

            if (j < m - 1 && grid[i][j + 1] == 1) {

                q.push(pair<int, int>(i, j + 1));

                grid[i][j + 1] = grid[i][j] + 1;

            }

            q.pop();

        }

        return -1;

    }

};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends