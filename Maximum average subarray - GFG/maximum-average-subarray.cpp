// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int findMaxAverage(int arr[], int n, int k) {
        // code here
        int l = 0, r = 0, ind = -1, sum = 0, pre = 0;
        while(r < k) {
            sum += arr[r];
            r++;
        }
       
        pre = sum;
        ind = l;
        while(r < n) {
            sum += arr[r++];
            sum -= arr[l++];
           
            if(sum > pre) {
                pre = sum;
                ind = l;
            }
        }
        return ind;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxAverage(arr, n, k);
        for (int i = ans; i < ans + k; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends