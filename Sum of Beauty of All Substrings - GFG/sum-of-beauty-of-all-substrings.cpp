//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    int func(vector<int> &s){
        int minVal = INT_MAX, maxVal = INT_MIN;
        for(auto it : s){
            if(it > 0) {
                minVal = min(minVal, it);
                maxVal = max(maxVal, it);
            }
        }
        return maxVal - minVal;
    }
    public:
        int beautySum(string s) {
            int ans = 0;
            for(int i = 0; i < s.length(); i++){
                vector<int> alp(26, 0);
                for(int j = i; j < s.length(); j++){
                    alp[s[j] - 'a']++;
                    ans += func(alp);
                }
            }
            return ans;
        }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends