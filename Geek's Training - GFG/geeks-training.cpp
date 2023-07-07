//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> dp;
    int f(vector<vector<int>> &arr, int n, int idx) {
        if(n == 0) {
            int maxi = 0;
            for(int i=0; i<3; i++) {
                if(i != idx) {
                    maxi = max(maxi, arr[0][i]);
                }
            }
            return maxi;
        }    
        
        if(dp[n][idx] != -1) return dp[n][idx];
        
        int maxi = 0;
        for(int i=0; i<3; i++) {
            if(i != idx) {
                maxi = max(maxi, arr[n][i] + f(arr, n-1, i));
            }
        }
        return dp[n][idx] = maxi;
    }
    
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        dp = vector<vector<int>> (n, vector<int> (4, -1));
        return f(points, n-1, 3);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends