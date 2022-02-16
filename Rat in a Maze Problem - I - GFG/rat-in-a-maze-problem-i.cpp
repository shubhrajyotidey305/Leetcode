// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        vector<vector<bool>> vis (n, vector<bool>(n,0));
        string path = "";
        
        dfs(0,0, n, ans, m, vis, path);
        
        sort(ans.begin(), ans.end());
        return ans;
    }

    bool isSafe(int row, int col, int n, vector<vector<int>> &m, vector<vector<bool>> &vis){
        if(row == -1 or row == n or col == -1 or col == n or vis[row][col] or m[row][col]==0){
            return false;
        }    
        return true;
    }
    
    void dfs(int row, int col, int n, vector<string> &ans, vector<vector<int>> &m, vector<vector<bool>> &vis, string &path){
        if(row == -1 or row == n or col == -1 or col == n or vis[row][col] or m[row][col]==0){
            return;
        }   
        
        if(row == n-1 and col == n-1 and m[row][col]){
            ans.push_back(path);
            return;
        }
        
        vis[row][col] = true;
        
        if(isSafe(row+1, col, n, m, vis)){
            path += 'D';
            dfs(row+1, col, n, ans, m, vis, path);
            path.pop_back();
        }
        
        if(isSafe(row-1, col, n, m, vis)){
            path += 'U';
            dfs(row-1, col, n, ans, m, vis, path);
            path.pop_back();
        }
        
        if(isSafe(row, col+1, n, m, vis)){
            path += 'R';
            dfs(row, col+1, n, ans, m, vis, path);
            path.pop_back();
        }
        
        if(isSafe(row, col-1, n, m, vis)){
            path += 'L';
            dfs(row, col-1, n, ans, m, vis, path);
            path.pop_back();
        }
        vis[row][col] = false;
        
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends