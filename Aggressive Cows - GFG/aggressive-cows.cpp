//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:

    bool Valid(vector<int> &stalls,int n,int k,int mid){
        int pos = stalls[0];
        k--;
        for(int i=1;i<n;i++){
            if(k==0) return true;
            if(stalls[i]-pos>=mid){
                pos = stalls[i];
                k--;
            }
        }
        if(k==0) return true;
        return false;
    }
    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(),stalls.end());
        int low = 1, high = stalls[n-1]-stalls[0], mid;
        int res=0;
        while(low<=high){
            mid = (low+high)/2;
            if(Valid(stalls,n,k,mid)){
                // cout<<"h"<<mid<<endl;
                res = max(res,mid);
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends