//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long jumpingNums(long long X) {
        // code here
        queue<long long>q;
        for(int i=1;i<10;i++)
            q.push(i);
        long long ans = INT_MIN;
        while(!q.empty()){
            long long front = q.front();
            q.pop();
            if(front>X)
                continue;
            ans = max(ans,front);
            int rem = front%10;
            if(rem != 0)    
            q.push(front*10+(rem-1));
            if(rem != 9)
            q.push(front*10+(rem+1));
        }
        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.jumpingNums(X) << endl;
    }
    return 0;
}
// } Driver Code Ends