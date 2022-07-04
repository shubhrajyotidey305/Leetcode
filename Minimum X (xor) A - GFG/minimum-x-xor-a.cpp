// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        // code here
        int n = __builtin_popcount(b);
        bitset<32> set(a);
        bitset<32> num;
        for(int i=31; i>=0; i--) {
            if(set[i] == 1){
                if(n > 0) {
                    num[i] = 1;
                    n--;
                }
                
            }
            
            if(n == 0) break;
        }
        
        int i = 0;
        while(n) {
            if(num[i] == 0){
                num[i] = 1;
                n--;
            }
            i++;
        }
        
        return (int) num.to_ulong();
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}  // } Driver Code Ends