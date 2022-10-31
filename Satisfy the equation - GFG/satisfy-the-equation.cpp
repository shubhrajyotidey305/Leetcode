//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> satisfyEqn(int arr[], int n) {
        // code here
        map<int, vector<pair<int, int>>> mp;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int sum = arr[i] + arr[j];
                mp[sum].push_back({i, j});
            } 
        }
        
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int curr = arr[i] + arr[j];
                if(mp.count(curr)) {
                    for(auto it:mp[curr]) {
                        int x = it.first, y = it.second;
                        if(x != i and x != j and y != i and y != j) {
                            return {i, j, x, y};
                        }
                    }
                }
            }
        }
        return {-1, -1, -1, -1};
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        vector<int> ptr = ob.satisfyEqn(A,N);
        
        cout<<ptr[0]<<" "<<ptr[1]<<" "<<ptr[2]<<" "<<ptr[3]<<endl;
    }
    return 0;
}
// } Driver Code Ends