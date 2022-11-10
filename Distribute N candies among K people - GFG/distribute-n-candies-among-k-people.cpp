//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    #define ll long long
    vector<long long> distributeCandies(int n, int k) {
        // code here
        ll count = 0;
        vector<ll> arr(k);
        
        int l = 0, r = n-1;
        while(l <= r) {
            ll mid = l + (r-l)/2;
            ll sum = mid * (mid + 1) / 2;
            
            if(sum <= n) {
                count = mid / k;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        ll last = count * k;
        n -= (last * (last + 1)) / 2;
        
        ll i = 0;
        ll first = last + 1;
        
        while(n) {
            if(first <= n) {
                arr[i++] = first;
                n -= first;
                first++;
            } else {
                arr[i] += n;
                n = 0;
            }
        }
        
        for (int i = 0; i < k; i++)
            arr[i] += (count * (i + 1)) + (k * (count * (count - 1)) / 2);
        
        return arr;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        cin>>N>>K;
        
        Solution ob;
        vector<long long> res = ob.distributeCandies(N,K);
        
        for(int i=0; i<res.size(); i++)
            cout<<res[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends