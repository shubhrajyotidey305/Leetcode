// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> &a, int k) {
        // Code here.
        int n = a.size();
        if(n&1) return 0;
        
        unordered_map<int, int> freq;
        
        for(int i=0; i<n; i++) freq[a[i]%k]++;
        
        for(int i=0; i<n; i++){
            int rem = a[i]%k;
            
            if(2*rem == k){
                if(freq[rem]%2) 
                    return 0;
            }        
            else if(rem == 0){
                if(freq[rem]&1) 
                    return 0;
            }        
            else if(freq[rem] != freq[k-rem]) 
                return 0;
        }
        return 1;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}  // } Driver Code Ends